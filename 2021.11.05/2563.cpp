#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<vector<int>> board;
	board.resize(101);
	for (int i = 0; i <= 100; i++)
		board[i].resize(101, 0);

	int n;
	cin >> n;

	while (n > 0) {
	
		int left, right;
		cin >> left >> right;


		for (int i = right; i < right + 10; i++)
			for (int j = left; j < left + 10; j++)
				board[i][j]++;
		n--;
	}

	int answer = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (board[i][j] == 0)
				continue;

			if (board[i][j]>=1)
				answer++;
		}
	}

	cout << answer << "\n";
	return 0;
}