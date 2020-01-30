#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> input(20);
int n;
int getResult = -1;
void dfs(int index, int sum) {

	if (index == n + 1) {
		getResult = max(getResult, sum);
		return;
	}
	
	int rightindex = input[index].first;
	int rightvalue = input[index].second;

	if (index + rightindex <= n+1)
		dfs(index + rightindex, sum + rightvalue);
	dfs(index + 1, sum);
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> input[i].first >> input[i].second;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	init();
	dfs(1, 0);
	
	cout << getResult << "\n";
	return 0;
}