#include <iostream>
#include <string>

using namespace std;

int dp[105][105][105];

void lcs(string a, string b, string c) {

	string left = "0" + a;
	string middle = "0" + b;
	string right = "0" + c;

	int leftLength = left.size();
	int middleLength = middle.size();
	int rightLength = right.size();

	for (int i = 1; i < leftLength; i++) {
		for (int j = 1; j < middleLength; j++) {
			for (int k = 1; k < rightLength; k++) {
				if (left[i] == middle[j] && middle[j]== right[k]) {
					int value = dp[i - 1][j - 1][k - 1] + 1;
					dp[i][j][k] = value;
				}
				else {
					int max_value = dp[i - 1][j][k] > dp[i][j - 1][k] ? dp[i - 1][j][k] : dp[i][j - 1][k];
					max_value = max_value > dp[i][j][k - 1] ? max_value : dp[i][j][k - 1];
					dp[i][j][k] = max_value;
				}
			}
		}
	}
	cout << dp[leftLength - 1][middleLength - 1][rightLength - 1] << "\n";
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string left, middle, right;
	cin >> left >> middle >> right;

	lcs(left, middle, right);

	return 0;
}