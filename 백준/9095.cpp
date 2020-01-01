#include <iostream>

using namespace std;

int n;
int cnt = 0;
void dfs(int one, int two, int three, int sum) {
	if (n == sum) {
		cnt++;
		return;
	}
	if (n < sum)
		return;
	dfs(one + 1, two, three, sum + 1);
	dfs(one, two + 1, three, sum + 2);
	dfs(one, two, three+1, sum+3);

}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int testcase_n;
	cin >> testcase_n;

	while (testcase_n > 0) {
		
		cin >> n;
		cnt = 0;
		dfs(0, 0, 0, 0);
		cout << cnt << "\n";
		testcase_n--;
	}
	return 0;
}