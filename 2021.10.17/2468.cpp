#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int getAreaCnt(int waterLength, int n, vector<vector<int>> &board) {

	vector<vector<bool>> isVisited(n);
	for (int i = 0; i < n; i++)
		isVisited[i].resize(n, false);

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			if (board[i][j] <= waterLength)
				isVisited[i][j] = true;
		}

	
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isVisited[i][j] == true)
				continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			isVisited[i][j] = true;

			while (!q.empty()) {
				int size = q.size();
				for (int k = 0; k < size; k++) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int tk = 0; tk < 4; tk++) {
						int nextdy = y + dy[tk];
						int nextdx = x + dx[tk];

						if (nextdy >= n || nextdx >= n || nextdx < 0 || nextdy < 0)
							continue;

						if (isVisited[nextdy][nextdx] == true)
							continue;
						isVisited[nextdy][nextdx] = true;
						q.push({ nextdy, nextdx });
					}
				}
			}

			answer++;
		}
	}

	if (answer == 0)
		answer = 1;
	return answer;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	


	vector<vector<int>> board;
	board.resize(n);
	for (int i = 0; i < n; i++)
		board[i].resize(n, 0);


	int maxNum = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] > maxNum)
				maxNum = board[i][j];
		}

	int answer = 0;

	for (int i = 1; i <= maxNum; i++) {

		int areaCnt = getAreaCnt(i, n, board);
		answer = max(answer, areaCnt);

	}

	cout << answer << "\n";
	return 0;
}