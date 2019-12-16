#include <iostream>
#include <vector>

using namespace std;

int parent[201];
int map[201][201];
vector<int> correct_route;

int getParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	int a = getParent(x);
	int b = getParent(y);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int findParent(int x, int y) {
	int a = getParent(x);
	int b = getParent(y);

	if (a == b)
		return 1;
	else
		return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		correct_route.push_back(input);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j)
				continue;
			if (map[i][j] == 0)
				continue;
			if (findParent(i, j) == 1)
				continue;
			unionParent(i, j);
		}
	}

	int size = correct_route.size();
	bool is_possible = true;
	int check_value = -1;
	for (int i = 0; i < size; i++) {
		int value = correct_route[i];
		if (i == 0)
			check_value = getParent(value);
		else
			if (check_value != getParent(value)) {
				is_possible = false;
				break;
			}
	}
	if (is_possible)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}