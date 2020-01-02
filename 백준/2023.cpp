#include <iostream>
#include <math.h>

using namespace std;

int n;

bool isPrime(int n) {
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0)
			return false;
	}
	return true;
}
void dfs(int sum, int length) {
	if (length == n) {
		cout << sum << "\n";
		return;
	}

	for (int i = 0; i <= 9; i++) {
		int temp = sum * 10 + i;
		if (isPrime(temp) == true) {
			dfs(temp, length + 1);
		}
	}

}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);

	return 0;
}