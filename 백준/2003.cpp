#include <iostream>
#include <vector>

using namespace std;

vector<int> input(10001);

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> input[i];

	int leftPoint = 0; // 여기까지 뺐다.
	int rightPoint = 1; // 여기까지 더했다.
	long long sum = input[1];
	int getResult = 0;

	while (1) {
		if (leftPoint >= n && rightPoint >= n)
			break;
		
		if (sum == m) {
			getResult++;
			if (rightPoint == n) {
				leftPoint++;
				sum = sum - input[leftPoint];
			}
			else {
				rightPoint++;
				sum = sum + input[rightPoint];
			}
		}

		if (sum < m) {
			if (rightPoint == n) {
				leftPoint++;
				sum = sum - input[leftPoint];
				continue;
			}
			rightPoint++;
			sum += input[rightPoint];
		}

		if (sum > m) {
			leftPoint++;
			sum = sum - input[leftPoint];
		}
	}

	cout << getResult << "\n";
	return 0;
}