#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int leftNode;
	int rightNode; 
	int value;
};

bool compare(node x, node y) {
	if (x.value < y.value)
		return true;
	else if (x.value == y.value)
		return x.leftNode < y.leftNode;
	else
		return false;
}

int getParent(int index, vector<int> &parent) {
	if (parent[index] == index)
		return parent[index];
	else
		return parent[index] = getParent(parent[index], parent);
}

void unionParent(int leftNode, int rightNode, vector<int> &parent) {
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
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	vector<int> parent(v + 1);
	for (int i = 1; i <= v; i++)
		parent[i] = i;
	vector<node> graph;
	for (int i = 1; i <= e; i++) {
		int leftNode, rightNode, value;
		cin >> leftNode >> rightNode >> value;
		graph.push_back({ leftNode, rightNode, value });
	}

	sort(graph.begin(), graph.end(), compare);

	int output = 0;

	for (int i = 0; i < graph.size(); i++) {
		int leftNode = graph[i].leftNode;
		int rightNode = graph[i].rightNode;
		int value = graph[i].value;

		if (isUnionParent(leftNode, rightNode, parent) == true) {
			output += value;
			unionParent(leftNode, rightNode, parent);
		}
	}
	cout << output << "\n";
	return 0;
}