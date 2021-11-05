#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	n = n % 6;

	if (n == 0 || n==2 || n==4)
		cout << "CY\n";
	else if (n == 1 || n==3 || n==5)
		cout << "SK\n";

	return 0;
}