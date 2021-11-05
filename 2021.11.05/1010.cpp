#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[31][31];

long long getCombR(int n, int r) {
	if (dp[n][r] != -1)
		return dp[n][r];

	if (n == r || n == 1 || r == 0)
		return 1;
	else if (r == 1)
		return n;
	else {
		return dp[n][r]=getCombR(n - 1, r) + getCombR(n - 1, r - 1);
	}

}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i <= 30; i++)
		for (int j = 0; j <= 30; j++)
			dp[i][j] = -1;

	int tk;
	cin >> tk;

	while (tk > 0) {
		
		int left, right;
		cin >> left >> right;

		cout << getCombR(right, left) << "\n";
		tk--;
	}
	return 0;
}