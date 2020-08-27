#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string input;
	cin >> input;

	int getResult = 0;
	for (int i = 0; i < m; i++) {

		if (i + 2 < m && input[i + 1] == 'O' && input[i + 2] == 'I') {
			int zero = 0;
			while (i + 1 < m && input[i] == 'I' && input[i + 1] == 'O') {
				zero++;
				i = i + 2;
				if (i < m && input[i] == 'I' && zero == n) {
					zero--;
					getResult++;
				}
			}
		}
	}
	cout << getResult << "\n";
	return 0;
}