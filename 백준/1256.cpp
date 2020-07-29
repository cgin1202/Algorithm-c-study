#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> dp;

void init(int n, int m) {

	for (int i = 1; i <= n + m; i++) {
		dp[i][1] = i;
		dp[i][i] = 1;
		dp[i][0] = 1;
	}

	for (int i = 2; i <= n + m; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			if (dp[i][j] > 1e9)
				dp[i][j] = (1e9)+1;
		}
	}
}

bool error = false;

void getResult(int n, int m, int k, int length, int maxLength, string output) {

	if (length == maxLength) {
		for (int i = 0; i < length; i++)
			cout << output << "\n";
		return;
	}

	if (n == 0) {
		for (int i = 0; i < m; i++)
			output += "z";
		cout << output << "\n";
		return;
	}

	if (m == 0) {
		for (int i = 0; i < n; i++)
			output += "a";
		cout << output << "\n";
		return;
	}

	int pointNum = dp[n + m-1][n-1];

	if (k <= pointNum)
		getResult(n-1, m, k, length + 1, maxLength, output + "a");
	else if (k <= 1e9)
		getResult(n, m - 1, k - pointNum, length + 1, maxLength, output + "z");
	else {
		error = true;
		return;
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;


	dp.resize(n + m + 1, vector<int>(n + m + 1, 0));
	init(n, m);

	bool visited = false;

	if (dp[n + m][n] < k || dp[n + m][m] < k)
		error = true;

	if (error == true) {
		cout << "-1\n";
		visited = true;
	}
	else
		getResult(n, m, k, 0, n+m, "");

	if (visited==false && error == true)
		cout << "-1\n";
	return 0;
}