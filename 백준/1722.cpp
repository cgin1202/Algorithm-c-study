#include <iostream>
#include <vector>

using namespace std;

vector<int> output;
long long twoOutput=0;

void getPermutation(int length, int n, long long k, vector<long long> &dp, vector<bool> &isVisited) {
	if (length == n)
		return;

	long long sum = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1 - length] == 0) {
			index = 0;
			break;
		}
		sum = dp[n - 1 - length] * i;
		if (sum > k)
			break;
		else
			index = i;
	}

	k = k - dp[n - 1 - length] * index;
	int cnt = 0;
	int realIndex = 0;
	for (int i = 0; i < n; i++) {
		if (isVisited[i+1] == true)
			continue;
		if (cnt == index) {
			realIndex = i;
			break;
		}
		cnt++;
	}
	isVisited[realIndex+1] = true;
	output.push_back(realIndex + 1);
	getPermutation(length + 1, n, k, dp, isVisited);
}

void init(int n, vector<long long> &dp) {
	dp.resize(n + 1);
	long long result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
		dp[i] = result;
	}
}

void getLength(int idx, int n, int length, vector<long long> &dp, vector<bool> &isVisited, vector<int> &input) {
	if (length == n)
		return;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (isVisited[i] == true)
			continue;
		if (input[idx] == i) {
			isVisited[i] = true;
			break;
		}
		cnt++;
	}

	twoOutput = twoOutput + dp[n - 1 - length] * cnt;

	getLength(idx + 1, n, length + 1, dp, isVisited, input);
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int choiceNum;
	cin >> choiceNum;

	vector<long long> dp;
	init(n, dp);

	if (choiceNum == 1) {
		long long k;
		cin >> k;
		vector<bool> isVisited(n+1);
		for (int i = 1; i <= n; i++)
			isVisited[i] = false;
		getPermutation(0, n, k-1, dp, isVisited);
		for (int i = 0; i < output.size(); i++)
			cout << output[i] << " ";
		cout << "\n";
	}
	else {
		vector<int> input(n);
		for (int i = 0; i < n; i++)
			cin >> input[i];
		vector<bool> isVisited(n+1);
		for (int i = 1; i <= n; i++)
			isVisited[i] = false;
		getLength(0, n, 0, dp, isVisited, input);
		cout << twoOutput+1 << "\n";
	}

	return 0;
}