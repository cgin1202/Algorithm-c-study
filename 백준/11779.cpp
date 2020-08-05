#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 처음에 bfs로 풀어도 된다고 생각하였으나
// bfs의 한계점은 가중치에 대해서까지는 보지 못한다는 것을 깨닫고 다익스트라로 바꿈
// 방문하였떤 노드에 대해서 다시 방문해야 하는 경우가 있기 때문

void getClosestLength(int startPoint, int endPoint, int n, vector<vector<pair<int, int>>> &graph) {

	vector<int> dist(n + 1);
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
		dist[i] = 1e9 + 1;
	dist[startPoint] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, startPoint });

	while (!pq.empty()) {

		int presentValue = -pq.top().first;
		int presentNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[presentNode].size(); i++) {
			int nextValue = graph[presentNode][i].first;
			int nextNode = graph[presentNode][i].second;

			if (presentValue + nextValue < dist[nextNode]) {
				dist[nextNode] = presentValue + nextValue;
				pq.push({ -dist[nextNode] , nextNode });
				parent[nextNode] = presentNode;
			}
		}
	}

	cout << dist[endPoint] << "\n";

	int index = endPoint;
	vector<int> path;
	path.push_back(index);
	while (1) {
		if (parent[index] == startPoint)
			break;
		index = parent[index];
		path.push_back(index);
	}
	path.push_back(startPoint);
	cout << path.size() << "\n";
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
	cout << "\n";
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph;
	graph.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int leftNode, rightNode, value;
		cin >> leftNode >> rightNode >> value;
		graph[leftNode].push_back({ value, rightNode });
	}

	int startPoint, endPoint;
	cin >> startPoint >> endPoint;

	getClosestLength(startPoint, endPoint, n, graph);

	return 0;
}