#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int getParent(vector<int> &parent, int input) {
	if (parent[input] == input)
		return input;
	else
		return parent[input]=getParent(parent, parent[input]);
}

void connectPossible(vector<int> &parent, int leftNode, int rightNode) {
	int leftParent = getParent(parent, leftNode);
	int rightParent = getParent(parent, rightNode);

	if (leftParent <= rightParent)
		parent[rightParent] = leftParent;
	else
		parent[leftParent] = rightParent;
}

bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.first < right.first)
		return true;
	else if (left.first == right.first)
		return left.second < right.second;
	else
		return false;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	vector<pair<int, int>> node;
	for (int i = 1; i <= m; i++) {
		int left, right;
		cin >> left >> right;
		node.push_back({ left, right });
		node.push_back({  right, left });
	}

	sort(node.begin(), node.end(), compare);

	for (int i = 0; i < node.size(); i++)
		connectPossible(parent, node[i].first, node[i].second);

	map<int, int> countResult;

	for (int i = 1; i <= n; i++)
		countResult[parent[i]]=1;

	cout << countResult.size() << "\n";
	return 0;
}

