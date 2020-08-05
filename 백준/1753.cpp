#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void getClosestLength(int n, int startPoint, vector<vector<pair<int, int>>> &graph) {
	vector<int> dist(n + 1);
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9 + 1;
	dist[startPoint] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, startPoint });

	while (!pq.empty()) {

		int presentValue = -pq.top().first;
		int presentNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[presentNode].size();  i++) {
			int nextValue = graph[presentNode][i].first;
			int nextNode = graph[presentNode][i].second;

			if (presentValue + nextValue < dist[nextNode]) {
				dist[nextNode] = presentValue + nextValue;
				pq.push({ -dist[nextNode] , nextNode });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i == startPoint)
			cout << "0\n";
		else {
			if (dist[i] == 1e9 + 1)
				cout << "INF\n";
			else
				cout << dist[i] << "\n";
		}
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int startPoint;
	cin >> startPoint;

	vector<vector<pair<int, int>>> graph;
	graph.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int leftNode, rightNode, value;
		cin >> leftNode >> rightNode >> value;
		graph[leftNode].push_back({ value, rightNode });
	}

	getClosestLength(n, startPoint, graph);
	return 0;
}