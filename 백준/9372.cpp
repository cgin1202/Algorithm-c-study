#include <iostream>
#include <vector>

using namespace std;

int getParent(int idx, vector<int> &parent) {
	if (parent[idx] == idx)
		return parent[idx] = idx;
	else
		return parent[idx] = getParent(parent[idx], parent);
}

void unionParent(int leftNode, int rightNode, vector<int>& parent) {
	int leftParent = getParent(leftNode, parent);
	int rightParent = getParent(rightNode, parent);
	if (leftParent <= rightParent)
		parent[rightParent] = leftParent;
	else
		parent[leftParent] = rightParent;
}

bool isUnionParent(int leftNode, int rightNode, vector<int>& parent) {
	int leftParent = getParent(leftNode, parent);
	int rightParent = getParent(rightNode, parent);
	if (leftParent == rightParent)
		return false;
	else
		return true;
}
int minAirplaneCnt(vector<pair<int, int>>& node, vector<int>& parent) {
	int count = 0;
	for (int i = 0; i < node.size(); i++) {
		int leftNode = node[i].first;
		int rightNode = node[i].second;
		if (isUnionParent(leftNode, rightNode, parent) == true) {
			count++;
			unionParent(leftNode, rightNode, parent);
		}

	}
	return count;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int tk;
	cin >> tk;

	while (tk > 0) {

		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> node;
		for (int i = 0; i < m; i++) {
			int leftNode, rightNode;
			cin >> leftNode >> rightNode;
			node.push_back({ leftNode, rightNode });
		}

		vector<int> parent(n + 1);
		for (int i = 1; i <= n; i++)
			parent[i] = i;

		cout << minAirplaneCnt(node, parent) <<"\n";

		tk--;
	}

	return 0;
}