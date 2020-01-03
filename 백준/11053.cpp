#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
vector<int> v;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	int max_result = 0;
	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				max = max > dp[j]?max:dp[j];
			}
		}
		dp[i] = max + 1;
		max_result = max_result > dp[i]?max_result:dp[i];
	}
	cout << max_result << "\n";
	return 0;
}