#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void checkIceberg(int n, int m, int startX, int startY, vector<vector<int>> &board, vector<vector<bool>> &isVistedBoard) {
	
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	isVistedBoard[startY][startX] = true;
	
	while (!q.empty()) {
		int presentY = q.front().first;
		int presentX = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nextdy = dy[k] + presentY;
			int nextdx = dx[k] + presentX;
			
			if (nextdy<1 || nextdx< 1 || nextdy > n || nextdx > m)
				continue;
			if (board[nextdy][nextdx] == 0)
				continue;
			if (isVistedBoard[nextdy][nextdx] == true)
				continue;
			isVistedBoard[nextdy][nextdx]= true;
			q.push({ nextdy, nextdx });
		}
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board;
	board.resize(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	int answer = 0;
	bool error = false;

	while (1) {

		// 빙산 구하기 O(N^2)
		vector<pair<int, int>> iceberg;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				if (board[i][j] != 0)
					iceberg.push_back({ i, j });
		}

		vector<vector<bool>> isVistedBoard;
		isVistedBoard.resize(n + 1, vector<bool>(m + 1, false));


		// 빙산 두 덩어리 이상으로 분리되는 지 check O(N^2)
		// 구한 iceberg에 대해서 하나 잡고 bfs 돌려서 다 방문한 다음에 빠져나왔을 때 방문안한 노드 있으면 2개 이상임!
		// 종료조건 1. 두덩어리 이상으로 분리
		if (iceberg.size() == 0) {
			error = true;
			break;
		}

		int cnt = 0;
		bool gameover = false;

		for (int i = 0; i < iceberg.size(); i++) {
			if (isVistedBoard[iceberg[i].first][iceberg[i].second] == true)
				continue;
			if (cnt == 1) {
				gameover = true;
				break;
			}
			checkIceberg(n, m, iceberg[i].second, iceberg[i].first, board, isVistedBoard);
			cnt++;
		}
		if (gameover == true)
			break;


		// 빙산에 대해서 상하좌우 보고 바다 개수만큼 board 최신화하기

		vector<int> countStore(iceberg.size());
		for (int i = 0; i < iceberg.size(); i++) {
			int presentY = iceberg[i].first;
			int presentX = iceberg[i].second;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nextdy = dy[k] + presentY;
				int nextdx = dx[k] + presentX;

				if (nextdy<1 || nextdx< 1 || nextdy > n || nextdx > m)
					continue;
				if (board[nextdy][nextdx] == 0)
					cnt++;
			}
			countStore[i] = max(board[presentY][presentX] - cnt, 0);
		}

		for (int i = 0; i < iceberg.size(); i++)
			board[iceberg[i].first][iceberg[i].second] = countStore[i];

		answer++;
	}
	
	if (error == true)
		cout << "0\n";
	else
		cout << answer << "\n";
	return 0;
}