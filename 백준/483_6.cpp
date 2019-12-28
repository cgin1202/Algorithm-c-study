#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 999999999
using namespace std;

vector<pair<int, int>> v;

int dist[101][101];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for(int i=1; i<=100; i++)
		fill(dist[i], dist[i] + 100, MAX);

	for (int i = 0; i < m; i++) {
		int left, right;
		cin >> left >> right;
		v.push_back({ left, right });
		dist[left][right] = 1;
		dist[right][left] = 1;
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	bool check = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] > 6)
				check = true;
		}
	}
	if (check == true)
		cout << "Big World!" << "\n";
	else
		cout << "Small World!" << "\n";
	return 0;
}