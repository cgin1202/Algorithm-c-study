#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string leftinput, rightinput;
int dp[1001][1001];

void getResult() {
	leftinput = "0" + leftinput;
	rightinput = "0" + rightinput;
	
	int leftLength = leftinput.size();
	int rightLength = rightinput.size();

	for (int i = 0; i < leftLength; i++)
		dp[i][0] = i;
	for (int i = 0; i < rightLength; i++)
		dp[0][i] = i;

	for (int i = 1; i < leftLength; i++) {
		for (int j = 1; j < rightLength; j++) {
			if (leftinput[i] == rightinput[j])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
		}
	}
	cout << dp[leftLength-1][rightLength-1] << "\n";
}

void init() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> leftinput >> rightinput;

}

int main() {

	init();
	getResult();
	return 0;

}