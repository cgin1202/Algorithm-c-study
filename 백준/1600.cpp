#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct queueData{
	int x;
	int y;
	int k;
};

int findEndPoint(int n, int m, int k, int startX, int startY, int endX, int endY, vector<vector<int>> &board, vector<vector<vector<bool>>> isVisitedBoard) {
	

	queue<queueData> q;
	q.push({ startX, startY, k });
	isVisitedBoard[k][startY][startX] = true;
	int length = 0;
	bool error = true;

	int horsedx[] = {2, 1, -1, -2, 2, 1, -1, -2};
	int horsedy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int presentY = q.front().x;
			int presentX = q.front().y;
			int presentk = q.front().k;

			q.pop();

			if (presentY == endY && presentX == endX) {
				error = false;
				break;
			}
			
			for (int tk = 0; tk < 4; tk++) {
				int nextX = presentX + dx[tk];
				int nextY = presentY + dy[tk];
				if (nextX<1 || nextY < 1 || nextX >m || nextY >n)
					continue;
				if (board[nextY][nextX] == 1)
					continue;
				if (isVisitedBoard[presentk][nextY][nextX] == true)
					continue;
				isVisitedBoard[presentk][nextY][nextX] = true;
				q.push({ nextY, nextX, presentk });
			}

			if (presentk > 0) {
				for (int tk = 0; tk < 8; tk++) {
					int nextX = presentX + horsedx[tk];
					int nextY = presentY + horsedy[tk];
					if (nextX<1 || nextY < 1 || nextX >m || nextY >n)
						continue;
					if (board[nextY][nextX] == 1)
						continue;
					if (isVisitedBoard[presentk-1][nextY][nextX] == true)
						continue;
					isVisitedBoard[presentk-1][nextY][nextX] = true;
					q.push({ nextY, nextX, presentk -1 });
				}
			}


		}
		if (error == false)
			break;
		length++;
	}

	if (error == true)
		return -1;
	else
		return length;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int k;
	cin >> k;

	int n, m;
	cin >> m >> n;

	vector<vector<int>> board;
	board.resize(n + 1, vector<int>(m + 1, 0));

	vector<vector<vector<bool>>> isVistedBoard;
	isVistedBoard.resize(k+1);
	for(int i=0; i<=k; i++)
		isVistedBoard[i].resize(n + 1, vector<bool>(m + 1, false));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	int startPointX = 1;
	int startPointY = 1;
	int endPointX = m;
	int endPointY = n;
	
	cout << findEndPoint(n, m, k, startPointX, startPointY, endPointX, endPointY, board, isVistedBoard)<<"\n";

	return 0;
}