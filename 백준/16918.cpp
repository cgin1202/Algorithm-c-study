#include <iostream>
#include <vector>

using namespace std;


vector<pair<int, int>> getBombPosition(vector<pair<int, int>> input, int n, int m) {
	vector<pair<int, int>> output;

	vector<vector<bool>> visited;
	visited.resize(n, vector<bool>(m, false));

	int dy[] = { 1,-1,0,0 };
	int dx[] = { 0,0,-1,1 };

	for (int i = 0; i < input.size(); i++) {
		int y = input[i].first;
		int x = input[i].second;
		
		visited[y][x] = true;
		output.push_back({ y, x });

		for (int k = 0; k < 4; k++) {
			int nextdy = dy[k] + y;
			int nextdx = dx[k] + x;
			if (nextdy >= n || nextdy < 0 || nextdx >= m || nextdx < 0)
				continue;
			if (visited[nextdy][nextdx] == true)
				continue;
			visited[nextdy][nextdx] = true;
			output.push_back({ nextdy, nextdx });
		}

	}
	return output;
}
vector<pair<int, int>> getZeroPosition(vector<vector<char>> board, int n, int m) {
	vector<pair<int, int>> getResult;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 'O')
				getResult.push_back({ i, j });

	return getResult;
}

void init(vector<vector<char>> &board, int n, int m) {
	board.resize(n, vector<char>(m, '.'));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c",&board[i][j]);
}

int main() {

	int n, m, time;
	cin >> n >> m >> time;

	vector<vector<char>> board;
	
	init(board, n, m);
	
	int presentTime = 0;
	bool presentStatus_1second = true;
	bool presentStatus_2second = false;
	bool presentStatus_3second = false;

	vector<pair<int, int>> zeroPosition;
	vector<pair<int, int>> bombPosition;

	while (1) {

		if (presentTime == time) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					cout << board[i][j];
				cout << "\n";
			}
			break;
		}

		// 초기 1초
		// 1. 'O' 위치 파악
		// 2. 'O' 현재 위치 기준으로 겹치는 부분 위치 파악
		// 3. 2초로 상태 바꾸기

		if (presentStatus_1second == true) {
			zeroPosition = getZeroPosition(board, n, m);
			bombPosition = getBombPosition(zeroPosition, n, m);
			presentStatus_1second = false;
			presentStatus_2second = true;
			presentTime++;
			continue;
		}

		// 초기 2초
		// 1. 전부 'O'으로 만들기
		// 1. 3초로 상태 바꾸기

		if (presentStatus_2second == true) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					board[i][j] = 'O';
			presentStatus_2second = false;
			presentStatus_3second = true;
			presentTime++;
			continue;
		}

		// 초기 3초 (초기 1초에서 'O') 상하좌우 다 터트리기
		// 1. 1-2번에 해당되는 애들 .으로 만들기, '0'위치 전부 초기화, 위치 파악한 거 초기화
		// 2. 1초로 상태바꾸기

		if (presentStatus_3second == true) {
			for (int i = 0; i < bombPosition.size(); i++) {
				int y = bombPosition[i].first;
				int x = bombPosition[i].second;
				board[y][x] = '.';
			}
			bombPosition.clear();
			zeroPosition.clear();
			presentStatus_3second = false;
			presentStatus_1second = true;
			continue;
		}
	}

	return 0;
}