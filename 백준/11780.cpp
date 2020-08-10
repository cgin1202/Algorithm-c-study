#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> output;

void findRoute(vector<vector<int>> &remember, int start, int end) {
	
	if (remember[start][end] == 0) {
		output.push_back(start);
		output.push_back(end);
		return;
	}
	
	findRoute(remember, start, remember[start][end]);
	output.pop_back();
	findRoute(remember, remember[start][end], end);
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> node;
	vector<vector<int>> remeber;

	node.resize(n+1, vector<int> (n+1, 1e9+1));
	remeber.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; i++) {
		int leftNode, rightNode, value;
		cin >> leftNode >> rightNode >> value;
		node[leftNode][rightNode] = min(node[leftNode][rightNode], value);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (node[i][j] > node[i][k] + node[k][j]) {
					node[i][j] = node[i][k] + node[k][j];
					remeber[i][j] = k;
				}
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				node[i][j] = 0;
			if (node[i][j] == 1e9 + 1)
				node[i][j] = 0;
			cout << node[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i==j || node[i][j] == 1e9 + 1)
				cout << "0\n";
			else {
				output.clear();
				findRoute(remeber, i, j);
				cout << output.size() << " ";
				for (int i = 0; i < output.size(); i++)
					cout << output[i] << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}