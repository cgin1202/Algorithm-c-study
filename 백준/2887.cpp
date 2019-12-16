#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct node {
	int index;
	int left;
	int right;
	int value;
};

struct edge_graph {
	int left;
	int right;
	int value;
};
bool compare_x(node x, node y){
	if (x.left < y.left)
		return true;
	else
		return false;
}

bool compare_y(node x, node y) {
	if (x.right < y.right)
		return true;
	else
		return false;
}

bool compare_z(node x, node y) {
	if (x.value < y.value)
		return true;
	else
		return false;
}

bool compare(edge_graph x, edge_graph y) {
	if (x.value < y.value)
		return true;
	else
		return false;
}
int parent[100001];
vector<node> v;
vector<edge_graph> result;

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

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int left, right, value;
		cin >> left >> right >> value;
		v.push_back({ i, left, right, value });
	}

	sort(v.begin(), v.end(), compare_x);
	for (int i = 0; i < n-1; i++)
		result.push_back({v[i].index, v[i+1].index, abs(v[i].left-v[i+1].left)});

	sort(v.begin(), v.end(), compare_y);
	for (int i = 0; i < n - 1; i++)
		result.push_back({ v[i].index, v[i + 1].index, abs(v[i].right - v[i+1].right) });

	sort(v.begin(), v.end(), compare_z);
	for (int i = 0; i < n - 1; i++)
		result.push_back({ v[i].index, v[i + 1].index, abs(v[i].value - v[i+1].value) });

	sort(result.begin(), result.end(), compare);

	for (int i = 0; i < n; i++)
		parent[i] = i;

	int sum = 0;

	for (int i = 0; i < result.size()-1; i++) {
		if (findParent(result[i].left, result[i].right) == 1)
			continue;
		sum += result[i].value;
		unionParent(result[i].left, result[i].right);
	}

	cout << sum << "\n";
	return 0;
}