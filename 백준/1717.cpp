#include <iostream>
#include <vector>
#include <string>

using namespace std;

int parent[1000001];

int getParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		parent[b] = a;
		return a;
	}
	else {
		parent[a] = b;
		return b;
	}
}

string findParent(int a,  int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return "YES";
	else
		return "NO";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int k = 0; k < m; k++) {
		int op, left, right;
		cin >> op >> left >> right;
		if (op == 0)
			unionParent(left, right);
		if (op == 1)
			cout << findParent(left, right) << "\n";
	}

	return 0;
}