#include <iostream>
#include <string>

using namespace std;

int dp[1005][1005];

void lcs(string a, string b) {
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

	cout << dp[left_length - 1][right_length - 1] << "\n";

	int present_value = dp[left_length - 1][right_length - 1];
	int compare_value = present_value - 1;

	string lcs = "";
	for (int i = left_length - 1; i >= 1; i--) {
		for (int j = right_length - 1; j >= 1; j--) {
			if (dp[i][j] == present_value && dp[i - 1][j] == compare_value && dp[i][j - 1] == compare_value && dp[i - 1][j - 1] == compare_value) {
				present_value--;
				compare_value--;
				lcs = left[i] + lcs;
				break;
			}
		}
	}
	cout << lcs << "\n";
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	lcs(a, b);
	return 0;
}