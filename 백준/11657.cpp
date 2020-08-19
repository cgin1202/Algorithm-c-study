#include <iostream>
#include <vector>
#include <algorithm>



#define INF 987654321

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	long long n, m;
	cin >> n >> m;

	vector<vector<long long>> graph;
	graph.resize(n + 1, vector<long long>(n + 1, INF));

	for (long long i = 0; i < m; i++) {
		long long startNode, endNode, value;
		cin >> startNode >> endNode >> value;
		graph[startNode][endNode] = min(graph[startNode][endNode], value);
	}
	vector<long long> dist(n + 1);
	for (long long i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;
	bool isCycle = false;


	for (long long i = 1; i <= n; i++) {

		for (long long j = 1; j <= n; j++) {

			if (dist[j] == INF)
				continue;
			for (long long k = 1; k <= n; k++) {
				if (graph[j][k] == INF)
					continue;

				long long value = graph[j][k];
				if (dist[k] > dist[j] + value) {
					dist[k] = dist[j] + value;
					if (i == n) {
						cout << "-1\n";
						return 0;
					}
				}
			}
		}
	}

	for (long long i = 2; i <= n; i++) {
		if (dist[i] == INF)
			cout << "-1\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}