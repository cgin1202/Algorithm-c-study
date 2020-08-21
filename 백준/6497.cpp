#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getShortestSumLength(int n, int m, vector<vector<pair<int, int>>> &graph) {

	vector<bool> isVisited(n + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	int index = 1;
	for(int i=1; i<=n; i++)
		if (graph[i].size() > 0) {
			index = i;
			break;
		}
	
	for (int i = 0; i < graph[index].size(); i++)
		pq.push({ graph[index][i].first, graph[index][i].second });
	isVisited[index] = true;
	int output = 0;

	while (!pq.empty()) {
		
		int frontValue = pq.top().first;
		int frontNode = pq.top().second;
		pq.pop();

		if (isVisited[frontNode] == true)
			continue;
		output += frontValue;
		isVisited[frontNode] = true;

		for (int i = 0; i < graph[frontNode].size(); i++) {
			int nextValue = graph[frontNode][i].first;
			int nextNode = graph[frontNode][i].second;
			pq.push({ nextValue, nextNode });
		}
	}

	return output;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		vector<vector<pair<int, int>>> graph(n + 1);

		int maxSum = 0;
		for (int i = 0; i < m; i++) {
			int leftNode, rightNode;
			cin >> leftNode >> rightNode;
			int value;
			cin >> value;
			maxSum += value;
			graph[leftNode].push_back({ value, rightNode });
			graph[rightNode].push_back({ value, leftNode });
		}

		cout << maxSum - getShortestSumLength(n, m, graph) << "\n";
	}
	return 0;
}