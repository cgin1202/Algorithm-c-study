#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
int get_result = 0;

void dfs(int idx, int sum) {
	if (idx >= n)
		return;
	
	sum += v[idx];
	if (sum == m)
		get_result++;
	dfs(idx + 1, sum - v[idx]);
	dfs(idx + 1, sum);
	
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	dfs(0, 0);
	
	cout << get_result << "\n";
	return 0;
}