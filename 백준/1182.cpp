#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int getResult = 0;
	int boundaryNum = 1 << n;
	for (int i = 1; i < boundaryNum; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum += arr[j];
		if (sum == m)
			getResult++;
	}

	cout << getResult << "\n";
	return 0;
}