#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &graph, int n) {
	vector<bool> isVisited(n + 1, false);
	queue<int> q;
	q.push(1);
	isVisited[1] = true;
	int length = 0;
	int cnt = 0;

	while (!q.empty()) {
		int qSize = q.size();
		if (length > 2)
			return cnt-1;
		for (int i = 0; i < qSize; i++) {
			int presentNode = q.front();
			q.pop();
			cnt++;

			for (int j = 0; j < graph[presentNode].size(); j++) {
				int nextNode = graph[presentNode][j];
				if (isVisited[nextNode] == true)
					continue;
				isVisited[nextNode] = true;
				q.push(nextNode);
			}
		}
		length++;
	}
	return cnt-1;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph;
	graph.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int leftNode, rightNode;
		cin >> leftNode >> rightNode;
		graph[leftNode].push_back(rightNode);
		graph[rightNode].push_back(leftNode);
	}

	cout << bfs(graph, n) << "\n";
	return 0;
}