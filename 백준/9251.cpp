#include <iostream>
#include <string>

using namespace std;

int dp[1005][1005];

int lcs(string b, string a) {
	string left = "0" + a;
	string right = "0" + b;

	int left_length = left.size();
	int right_length = right.size();


	for (int i = 1; i < left_length; i++) {
		for (int j = 1; j < right_length; j++) {
			if (left[i] == right[j]) {
				int value = dp[i - 1][j - 1] + 1;
				dp[i][j] = value;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}

	return dp[left_length-1][right_length - 1];
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	cout << lcs(a, b) << "\n";
	return 0;
}