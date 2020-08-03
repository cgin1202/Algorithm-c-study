#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getHouseLength(int startX, int startY, int n, vector<vector<int>> &board, vector<vector<bool>> & isVistedBoard) {
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	isVistedBoard[startY][startX] = true;

	int length = 1;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!q.empty()) {
		int presentY = q.front().first;
		int presentX = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nextdy = presentY + dy[k];
			int nextdx = presentX + dx[k];
			if (nextdx<1 || nextdy<1 || nextdx>n || nextdy>n)
				continue;

			if (isVistedBoard[nextdy][nextdx] == true)
				continue;

			if (board[nextdy][nextdx] == 0)
				continue;
			isVistedBoard[nextdy][nextdx] = true;
			q.push({ nextdy, nextdx });
			length++;
		}
	}
	return length;
}
int main() {	
	int n;
	cin >> n;

	vector<vector<int>> board;
	board.resize(n + 1, vector<int>(n + 1, 0));

	vector<vector<bool>> isVistedBoard;
	isVistedBoard.resize(n + 1, vector<bool>(n + 1, false));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf(" %1d", &board[i][j]);
	}

	vector<int> output;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 0)
				continue;
			if (isVistedBoard[i][j] == true)
				continue;
			int houseLength = getHouseLength(j, i, n, board, isVistedBoard);
			output.push_back(houseLength);
		}
	}

	sort(output.begin(), output.end());
	cout << output.size() << "\n";
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << "\n";
	return 0;
}