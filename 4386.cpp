#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

struct graph {
	int leftNode;
	int rightNode;
	double value;
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
	int n;
	cin >> n;

	vector<pair<double, double>> node;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		node.push_back({ y,x });
	}

	vector<graph> nodeLine;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j)
				continue;
			
			double leftY = node[i].first;
			double leftX = node[i].second;
			double rightY = node[j].first;
			double rightX = node[j].second;
			double value = sqrt((leftY - rightY) * (leftY - rightY) + (leftX - rightX) * (leftX - rightX));
			
			nodeLine.push_back({ i, j, value });
		}
	}

	vector<int> parent(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;

	sort(nodeLine.begin(), nodeLine.end(), compare);

	double result = 0;

	for (int i = 0; i < nodeLine.size(); i++) {
		int leftNode = nodeLine[i].leftNode;
		int rightNode = nodeLine[i].rightNode;
		double value = nodeLine[i].value;
		if (isUnionParent(leftNode, rightNode, parent) == true) {
			result += value;
			unionParent(leftNode, rightNode, parent);
		}
	}

	printf("%.2lf",result);
	return 0;
}