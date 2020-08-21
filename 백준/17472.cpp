#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct nodeData {
	int leftNode;
	int rightNode;
	int value;
};

bool compare(nodeData x, nodeData y) {
	if (x.value < y.value)
		return true;
	else if (x.value == y.value)
		return x.leftNode < y.leftNode;
	else
		return false;
}

vector<pair<int, int>> searchSameGround(int y, int  x, int n, int m, vector<vector<int>> &graph, vector<vector<bool>> &isVisited) {
	vector<pair<int, int>> output;
	queue<pair<int, int>> q;
	q.push({ y,x });
	isVisited[y][x] = true;
	output.push_back({ y,x });
	int dx[] = {1,-1,0,0};
	int dy[] = {0, 0, 1, -1};

	while (!q.empty()) {
		int presentY = q.front().first;
		int presentX = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nextdy = presentY + dy[k];
			int nextdx = presentX + dx[k];

			if (nextdy > n || nextdx > m || nextdx < 1 || nextdy < 1)
				continue;
			if (isVisited[nextdy][nextdx] == true)
				continue;
			if (graph[nextdy][nextdx] == 0)
				continue;

			isVisited[nextdy][nextdx] = true;
			output.push_back({ nextdy,nextdx });
			q.push({ nextdy, nextdx });
		}
	}
	return output;
}

void findNodeLine(int groundNum, int y, int  x, int n, int m, vector<vector<int>>& graph, vector<nodeData> &nodeLine) {
	int dy[] = { 1,-1, 0, 0 };
	int dx[] = { 0, 0, 1,-1 };

	
	for (int k = 0; k < 4; k++) {
		int length = 1;
		while (1) {
			int nextdy = y + dy[k]*length;
			int nextdx = x + dx[k]*length;
			if (nextdy > n || nextdx > m || nextdy < 1 || nextdx < 1)
				break;
			if (graph[nextdy][nextdx] == groundNum)
				break;
			if (graph[nextdy][nextdx] != 0 && graph[nextdy][nextdx] != groundNum) {
				int leftNode = graph[y][x];
				int rightNode = graph[nextdy][nextdx];
				if (length == 2)
					break;
				nodeLine.push_back({ leftNode, rightNode, length-1 });
				break;
			}
			length++;
		}
	}
}

int getParent(int idx, vector<int> &parent) {
	if (parent[idx] == idx)
		return parent[idx] = idx;
	else
		return parent[idx] = getParent(parent[idx], parent);
}

void unionParent(int leftNode, int rightNode, vector<int>& parent) {
	int leftParent = getParent(leftNode, parent);
	int rightParent = getParent(rightNode, parent);

	if (leftParent <= rightParent)
		parent[rightParent] = leftParent;
	else
		parent[leftParent] = rightParent;
}

bool isUnionParent(int leftNode, int rightNode, vector<int>& parent) {
	int leftParent = getParent(leftNode, parent);
	int rightParent = getParent(rightNode, parent);

	if (leftParent == rightParent)
		return false;
	else
		return true;
}

bool isCheckDone(int areaNum, vector<int> &parent) {
	int x = parent[1];
	for (int i = 2; i < areaNum; i++) {
		int y = getParent(i, parent);
		if (x != y)
			return false;
	}
	return true;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph;
	graph.resize(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> graph[i][j];

	vector<vector<bool>> isVisted;
	isVisted.resize(n + 1, vector<bool>(m + 1, false));

	int groundNum = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (isVisted[i][j] == true)
				continue;
			if (graph[i][j] == 0)
				continue;
			vector<pair<int, int>> ground = searchSameGround(i, j, n, m, graph, isVisted);
			for (int k = 0; k < ground.size(); k++)
				graph[ground[k].first][ground[k].second] = groundNum;
			groundNum++;
		}
	}

	vector<nodeData> nodeLine;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 0)
				continue;
			findNodeLine(graph[i][j], i, j, n, m, graph, nodeLine);
		}
	}

	sort(nodeLine.begin(), nodeLine.end(), compare);

	vector<int> parent(groundNum + 1);
	for (int i = 1; i <= groundNum; i++)
		parent[i] = i;

	int output = 0;

	for (int i = 0; i < nodeLine.size(); i++) {
		int leftNode = nodeLine[i].leftNode;
		int rightNode = nodeLine[i].rightNode;
		int value = nodeLine[i].value;

		if (isUnionParent(leftNode, rightNode, parent) == true) {
			unionParent(leftNode, rightNode, parent);
			output += value;
		}
	}

	if (isCheckDone(groundNum, parent) == false)
		output = 0;

	if (output == 0)
		cout << "-1\n";
	else
		cout << output << "\n";
	return 0;
}