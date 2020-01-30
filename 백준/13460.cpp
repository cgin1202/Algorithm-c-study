#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m;
char board[11][11];
bool visited[11][11][11][11];

pair<int, int> red;
pair<int, int> blue;
queue<pair<int, int>> redQueue;
queue<pair<int, int>> blueQueue;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int startGame() {
		
	int length = 0;
	bool gameover = false;

	while (!redQueue.empty()) {
		int size = redQueue.size();
		for (int i = 0; i < size; i++) {
			int redData_x = redQueue.front().first;
			int redData_y = redQueue.front().second;
			int blueData_x = blueQueue.front().first;
			int blueData_y = blueQueue.front().second;
			redQueue.pop();
			blueQueue.pop();

			if (board[redData_x][redData_y] == 'O' && board[blueData_x][blueData_y] != 'O') {
				gameover = true;
				break;
			}


			for (int k = 0; k < 4; k++) {
				
				int nextRedData_x = redData_x;
				int nextRedData_y = redData_y;
				int nextBlueData_x = blueData_x;
				int nextBlueData_y = blueData_y;
				while (1) {
					nextRedData_x = nextRedData_x + dx[k];
					nextRedData_y = nextRedData_y + dy[k];
					if (board[nextRedData_x][nextRedData_y] == 'O')
						break;
					if (board[nextRedData_x][nextRedData_y] == '#') {
						nextRedData_x = nextRedData_x - dx[k];
						nextRedData_y = nextRedData_y - dy[k];
						break;
					}
				}

				while (1) {
					nextBlueData_x = nextBlueData_x + dx[k];
					nextBlueData_y = nextBlueData_y + dy[k];
					if (board[nextBlueData_x][nextBlueData_y] == 'O')
						break;
					if (board[nextBlueData_x][nextBlueData_y] == '#') {
						nextBlueData_x = nextBlueData_x - dx[k];
						nextBlueData_y = nextBlueData_y - dy[k];
						break;
					}
				}
				if (board[nextBlueData_x][nextBlueData_y] == 'O')
					continue;

				if (nextRedData_x == redData_x && nextBlueData_x == blueData_x && nextRedData_y == redData_y && nextBlueData_y == blueData_y)
					continue;

				if (nextRedData_x == nextBlueData_x && nextRedData_y == nextBlueData_y) {
					if (board[nextBlueData_x][nextBlueData_y] == 'O')
						continue;
					int redDistance = abs(nextRedData_x - redData_x) + abs(nextRedData_y - redData_y);
					int blueDistance = abs(nextBlueData_x - blueData_x) + abs(nextBlueData_y - blueData_y);
					if (redDistance < blueDistance) {
						nextBlueData_x = nextBlueData_x - dx[k];
						nextBlueData_y = nextBlueData_y - dy[k];
					}
					else {
						nextRedData_x = nextRedData_x - dx[k];
						nextRedData_y = nextRedData_y - dy[k];
					}
				}

				if (visited[nextRedData_x][nextRedData_y][nextBlueData_x][nextBlueData_y] == true)
					continue;
				visited[nextRedData_x][nextRedData_y][nextBlueData_x][nextBlueData_y] == true;
				redQueue.push({ nextRedData_x, nextRedData_y });
				blueQueue.push({ nextBlueData_x, nextBlueData_y });
			}
		}
		if (gameover == true)
			break;
		if (length > 10)
			break;
		length++;
	}
	if (length > 10)
		length = -1;
	return length;
}
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &board[i][j]);
			if (board[i][j] == 'R') {
				red.first = i;
				red.second = j;
				board[i][j] = '.';
			}
			if (board[i][j] == 'B') {
				blue.first = i;
				blue.second = j;
				board[i][j] = '.';
			}
		}
	redQueue.push(red);
	blueQueue.push(blue);
}
int main() {
	input();
	cout << startGame() << "\n";
	return 0;
}