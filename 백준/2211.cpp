#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void getShortestPath(int n, int m, vector<vector<pair<int, int>>> &node, vector<int> &parent, vector<int> &dist) {

	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int presentValue = -pq.top().first;
		int presentNode = pq.top().second;
		pq.pop();

		if (dist[presentNode] == 987654321)
			continue;
		for (int i = 0; i < node[presentNode].size(); i++) {
			int nextValue = node[presentNode][i].first;
			int nextNode = node[presentNode][i].second;
			if (dist[nextNode] > dist[presentNode] + nextValue) {
				dist[nextNode] = dist[presentNode] + nextValue;
				pq.push({ -dist[nextNode], nextNode });
				parent[nextNode] = presentNode;
			}
		}
	}

	vector<pair<int, int>> result;
	map<pair<int, int>, int> checkVisited;

	for (int i = 2; i <= n; i++) {
		int presentNode = i;
		while (presentNode != 1) {
			int nextNode = parent[presentNode];
			if (checkVisited.find({ presentNode, nextNode }) == checkVisited.end()) {
				if (checkVisited.find({ nextNode, presentNode }) == checkVisited.end()) {
					result.push_back({ presentNode, nextNode });
					checkVisited[{presentNode, nextNode}] = 1;
					checkVisited[{nextNode, presentNode}] = 1;
				}
			}
			presentNode = nextNode;
		}
	}
	
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i].first << " " << result[i].second << "\n";
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> node(n+1);

	for (int i = 0; i < m; i++) {
		int leftNode, rightNode, value;
		cin >> leftNode >> rightNode >> value;
		node[leftNode].push_back({ value, rightNode });
		node[rightNode].push_back({ value, leftNode });
	}

	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	vector<int> dist(n + 1, 987654321);

	getShortestPath(n, m, node, parent, dist);
	return 0;
}