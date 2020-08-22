#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> wisangSort(int n, vector<vector<int>> &node, vector<int> &getChildCnt) {
	queue<int> q;
	vector<int> output;
	for (int i = 1; i <= n; i++)
		if (getChildCnt[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int presentNode = q.front();
		q.pop();
		output.push_back(presentNode);

		for (int i = 0; i < node[presentNode].size(); i++) {
			int nextNode = node[presentNode][i];
			getChildCnt[nextNode]--;
			if (getChildCnt[nextNode] == 0)
				q.push(nextNode);
		}
	}
	return output;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> getChildCnt(n + 1, 0);
	vector<vector<int>> node(n+1);

	for (int i = 0; i < m; i++) {
		int leftNode, rightNode;
		cin >> leftNode >> rightNode;
		node[leftNode].push_back(rightNode);
		getChildCnt[rightNode]++;
	}

	vector<int> output = wisangSort(n, node, getChildCnt);

	for (int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	cout << "\n";

	return 0;
}