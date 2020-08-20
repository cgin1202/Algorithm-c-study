#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct graph {
	int leftNode;
	int rightNode;
	int value;
};

bool compare(graph x, graph y) {
	if (x.value < y.value)
		return true;
	else if (x.value == y.value)
		return x.leftNode < y.leftNode;
	else
		return false;
}

int getParent(int index, vector<int>& parent) {
	if (parent[index] == index)
		return parent[index];
	else
		return parent[index] = getParent(parent[index], parent);
}

void unionParent(int leftChild, int rightChild, vector<int>& parent) {
	int leftParent = getParent(leftChild, parent);
	int rightParent = getParent(rightChild, parent);

	if (leftParent <= rightParent)
		parent[rightParent] = leftParent;
	else
		parent[leftParent] = rightParent;
}

bool isUnionParent(int leftChild, int rightChild, vector<int>& parent) {
	int leftParent = getParent(leftChild, parent);
	int rightParent = getParent(rightChild, parent);

	if (leftParent == rightParent)
		return false;
	else
		return true;
}

int main() {
	
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n+1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	
	vector<graph> nodeLine;

	for (int i = 1; i <= m; i++) {
		int leftNode, rightNode, value;
		cin >> leftNode >> rightNode >> value;
		nodeLine.push_back({ leftNode, rightNode, value });
	}

	sort(nodeLine.begin(), nodeLine.end(), compare);
	int output = 0;

	for (int i = 0; i < nodeLine.size(); i++) {
		int leftNode = nodeLine[i].leftNode;
		int rightNode = nodeLine[i].rightNode;
		int value = nodeLine[i].value;

		if (isUnionParent(leftNode, rightNode, parent) == true) {
			output += value;
			unionParent(leftNode, rightNode, parent);
		}

	}

	cout << output << "\n";
	return 0;
}