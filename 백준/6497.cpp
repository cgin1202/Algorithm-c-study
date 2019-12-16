#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int left;
	int right;
	int value;
};

vector<node> v;
int parent[200001];

bool compare(node x, node y) {
	if (x.value < y.value)
		return true;
	else
		return false;
}

int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
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

	while (1) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;
		v.clear();

		int max_sum = 0;
		for (int i = 0; i < m; i++) {
			int left, right, value;
			cin >> left >> right >> value;
			max_sum = max_sum + value;
			v.push_back({ left, right, value });
		}

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < n; i++)
			parent[i] = i;

		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (findParent(v[i].left, v[i].right) == 1)
				continue;

			sum += v[i].value;
			unionParent(v[i].left, v[i].right);
		}

		cout << max_sum-sum << "\n";
	}
	return 0;
}