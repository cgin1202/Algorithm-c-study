#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void wisangSort(int n, vector<vector<int>> &node, vector<int> &getChildCnt) {
	queue<int> q;
	vector<int> output;
	for (int i = 1; i <= n; i++)
		if (getChildCnt[i] == 0)
			q.push(i);

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "0\n";
			return;
		}
		int presentNode = q.front();
		q.pop();
		output.push_back(presentNode);
		for (int j = 0; j < node[presentNode].size(); j++) {
			int nextNode = node[presentNode][j];
			getChildCnt[nextNode]--;
			if (getChildCnt[nextNode] == 0)
				q.push(nextNode);
		}
	}
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << "\n";
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> node(n + 1);
	vector<int> getChildCnt(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int tk;
		cin >> tk;

		vector<int> order;
		for (int j = 0; j < tk; j++) {
			int input;
			cin >> input;
			order.push_back(input);
		}

		for (int j = 0; j < tk-1; j++) {
			int leftNode = order[j];
			int rightNode = order[j + 1];
			node[leftNode].push_back(rightNode);
			getChildCnt[rightNode]++;
		}
	}

	wisangSort(n, node, getChildCnt);
	return 0;
}