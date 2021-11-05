#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);


	vector<int> arr;
	arr.push_back(0);
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= i; j++)
			arr.push_back(i);

	int n, m;
	cin >> n >> m;

	int answer = 0;
	for (int i = n; i <= m; i++) {
		answer += arr[i];
		//cout << arr[i] << "\t";
	}
	cout << answer << "\n";
	return 0;
}