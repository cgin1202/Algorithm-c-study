#include <iostream>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int testcase_n;
	cin >> testcase_n;

	int l_cnt = 'L' - 'A';
	while (testcase_n > 0) {
		
		int n, m;
		cin >> n >> m;

		if (n >= l_cnt + 1 && m >= 4) {
			int result = 0;
			result = result + (l_cnt) * m;
			result += 4;
			cout << result << "\n";
		}
		else {
			cout << "-1\n";
		}
		
		testcase_n--;
	}


	return 0;
}