#include <iostream>
#define INF 100000000
#include <algorithm>

using namespace std;

int map[101][101];

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int left, right, value;
		cin >> left >> right >> value;
		map[left][right] = min(map[left][right], value);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == INF)
				cout << "0 ";
			else
				cout << map[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}