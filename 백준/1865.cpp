#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int tk;
	cin >> tk;
	
	while (tk > 0) {

		int n, m, backN;
		cin >> n >> m >> backN;

		vector<int> dist(n + 1, 1e9 + 1);
		vector<vector<pair<int, int>>> graph;
		graph.resize(n + 1);

		dist[1] = 0;

		bool isMinusCycle = false;

		for (int i = 0; i < m; i++) {
			int leftNode, rightNode, value;
			cin >> leftNode >> rightNode >> value;
			graph[leftNode].push_back({ value, rightNode });
			graph[rightNode].push_back({ value, leftNode });
		}

		for (int i = 0; i < backN; i++) {
			int leftNode, rightNode, value;
			cin >> leftNode >> rightNode >> value;
			graph[leftNode].push_back({ -value, rightNode });
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < graph[j].size(); k++) {
					int nextValue = graph[j][k].first;
					int nextNode = graph[j][k].second;
					int presentNode = j;
					if (dist[nextNode] > dist[presentNode] + nextValue) {
						dist[nextNode] = dist[presentNode] + nextValue;
						if (i == n)
							isMinusCycle = true;
					}

				}
			}
		}

		if (isMinusCycle == true)
			cout << "YES\n";
		else
			cout << "NO\n";
		tk--;
	}


	return 0;
}