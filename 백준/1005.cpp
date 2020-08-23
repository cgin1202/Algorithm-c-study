#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int findBuildingSumvalue(int n, vector<vector<int>> &node, vector<int> &value, vector<int> inCount, int finalNum) {
	int sum = 0;

	vector<int> dp(n + 1, 0);

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (inCount[i] == 0) {
			q.push(i);
			dp[i] = value[i];
		}

	bool isGameover = false;

	while (!q.empty()) {
		int qSize = q.size();
	
		
		int presentNode = q.front();
		q.pop();
		
		if (presentNode == finalNum) {
			isGameover = true;
			break;
		}
		for (int j = 0; j < node[presentNode].size(); j++) {
			int nextNode = node[presentNode][j];
			inCount[nextNode]--;
			dp[nextNode] = max(dp[nextNode], dp[presentNode] + value[nextNode]);

			if (inCount[nextNode] == 0) {
				q.push(nextNode);
			}
		}
	}
	return dp[finalNum];
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int tk;
	cin >> tk;

	while (tk > 0) {

		int n, k;
		cin >> n >> k;
		vector<int> inCount(n + 1);
		vector<int> value(n + 1);
		vector<vector<int>> node(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> value[i];

		for (int i = 0; i < k; i++) {
			int leftNode, rightNode;
			cin >> leftNode >> rightNode;
			node[leftNode].push_back(rightNode);
			inCount[rightNode]++;
		}

		int finalNum;
		cin >> finalNum;


		cout << findBuildingSumvalue(n, node, value, inCount, finalNum) <<"\n";
		tk--;
	}

	return 0;
}