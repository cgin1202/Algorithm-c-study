#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> graph;
	graph.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0)
				graph[i][j] = 1e9 + 1;
		}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 1e9 + 1)
				graph[i][j] = 0;
			else
				graph[i][j] = 1;
			cout << graph[i][j] << " ";
		}
		cout << "\n";

	}
	return 0;
}