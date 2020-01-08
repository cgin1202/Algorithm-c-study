#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char map[51][51];
bool visited[51][51];
int end_i = 0;
int end_j = 0;
int start_i = 0;
int start_j = 0;
queue<pair<int, int>> water;
queue<pair<int, int>> gosum;

int dx[] = { 1,-1,0, 0 };
int dy[] = { 0,0,1,-1 };
bool gameover = false;

void water_move() {
	int size = water.size();
	for (int i = 0; i < size; i++) {
		int front_i = water.front().first;
		int front_j = water.front().second;
		water.pop();
		for (int k = 0; k < 4; k++) {
			int nextdx = front_i + dx[k];
			int nextdy = front_j + dy[k];
			if (nextdx <= n && nextdx >= 1 && nextdy <= m && nextdy >= 1) {
				if (visited[nextdx][nextdy] == true)
					continue;
				if ((nextdx==end_i && nextdy==end_j) || map[nextdx][nextdy] == 'X')
					continue;
				water.push({ nextdx, nextdy });
				visited[nextdx][nextdy] = true;
			}
		}
	}
}

void gosummove() {
	int size = gosum.size();
	for (int i = 0; i < size; i++) {
		int front_i = gosum.front().first;
		int front_j = gosum.front().second;
		gosum.pop();
		if (front_i == end_i && front_j == end_j) {
			gameover = true;
			return;
		}
		for (int k = 0; k < 4; k++) {
			int nextdx = front_i + dx[k];
			int nextdy = front_j + dy[k];
			if (nextdx <= n && nextdx >= 1 && nextdy <= m && nextdy >= 1) {
				if (visited[nextdx][nextdy] == true)
					continue;
				if (map[nextdx][nextdy] == '*' || map[nextdx][nextdy] == 'X')
					continue;
				gosum.push({ nextdx, nextdy });
				visited[nextdx][nextdy] = true;
			}
		}
	}
}
int main() {


	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				start_i = 0;
				start_j = 0;
				map[i][j] = 'S';
				gosum.push({ i,j });
				visited[i][j] = true;
			}
			else if (map[i][j] == 'D') {
				end_i = i;
				end_j = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == '*') {
				water.push({ i,j });
				visited[i][j] = true;
			}
			else if (map[i][j] == 'X') {
				visited[i][j] = true;
			}
		}
	}
	int cnt = 0;

	while (1) {
		if (gosum.size() == 0) {
			cout << "KAKTUS\n";
			break;
		}

		// water 범람
		water_move();

		// 고슴도치 이동
		gosummove();
		if (gameover == true) {
			cout << cnt << "\n";
			break;
		}
		cnt++;
	}
	return 0;
}