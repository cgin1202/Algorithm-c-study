#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int dp[101][101];
string word;
bool noWord=false;
int n, m, k;

void getWord(int a, int z, int skip) {
	if (a == 0) {
		for (int i = 0; i < z; i++)
			word += "z";
		return;
	}

	if (z==0) {
		for (int i = 0; i < a; i++)
			word += "a";
		return;
	}

	int skipNum = dp[a - 1][z];

	if (skip < skipNum) {
		word += "a";
		getWord(a - 1, z, skip);
	}
	else if (skip <= 1000000000) {
		word += "z";
		getWord(a, z-1, skip-skipNum);
	}
	else {
		noWord = true;
	}
}

void init() {

	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;

	for (int j = 1; j <= m; j++)
		dp[0][j] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1], 1000000009);
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	init();
	if (k > dp[n][m])
		noWord = true;
	else
		getWord(n, m, k - 1);

	if (noWord)
		cout << "-1\n";
	else
		cout << word << "\n";

	return 0;
}