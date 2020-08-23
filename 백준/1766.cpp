#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void wisangSort(int n, vector<vector<int>> &node, vector<int> &inCount) {
	priority_queue<int, vector<int>, greater<int>> q;
	vector<bool> isVisited(n + 1, false);

	for (int i = 1; i <= n; i++)
		if (inCount[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int presentNode = q.top();
		q.pop();
		if (isVisited[presentNode] == true)
			continue;
		cout << presentNode << " ";

		for (int i = 0; i < node[presentNode].size(); i++) {
			int nextNode = node[presentNode][i];
			if (isVisited[nextNode] == true)
				continue;
			inCount[nextNode]--;
			if (inCount[nextNode] == 0)
				q.push(nextNode);
		}
	}

	cout << "\n";
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> inCount(n + 1);
	vector<vector<int>> node(n + 1);
	for (int i = 0; i < m; i++) {
		int leftNode, rightNode;
		cin >> leftNode >> rightNode;

		inCount[rightNode]++;
		node[leftNode].push_back(rightNode);
	}

	for (int i = 1; i <= n; i++)
		sort(node[i].begin(), node[i].end());

	wisangSort(n, node, inCount);
	return 0;
}