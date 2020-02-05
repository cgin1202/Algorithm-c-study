#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

bool visited[101][101];
int board[101][101];
int n;
int k; 
int l;
vector<pair<int, string>> info;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0, 0 };

// 0 아래  1 위 2 오른쪽 3 왼쪽
int clock = 0;

int changeDir(int op, string dir) {
	if (op == 0) {
		if (dir == "L")
			return 2;
		else
			return 3;
	}
	else if (op == 1) {
		if (dir == "L")
			return 3;
		else
			return 2;
	}
	else if (op == 2) {
		if (dir == "L")
			return 1;
		else
			return 0;
	}
	else {
		if (dir == "L")
			return 0;
		else
			return 1;
	}
}

void init() {
	cin >> n;

	cin >> k;
	for (int i = 1; i <= k; i++) {
		int left, right;
		cin >> left >> right;
		board[left][right] = 1;
	}
	cin >> l;
	for (int i = 1; i <= l; i++) {
		int time;
		string dir;
		cin >> time >> dir;
		info.push_back({ time, dir });
	}
		
}

void playgame() {
	int start_x = 1;
	int start_y = 1;
	visited[start_y][start_x] = true;
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	int op = 2;
	int idx = 0;

	while (1) {
		if (idx<l && info[idx].first == clock) {
			string tempDir = info[idx].second;
			int tempOp= changeDir(op, tempDir);
			op = tempOp;
			idx++;
		}
		if (start_x<1 || start_y<1 || start_x>n || start_y>n)
			break;
		int nextdy = dy[op] + start_y;
		int nextdx = dx[op] + start_x;
		if (board[nextdy][nextdx] == 1) {
			board[nextdy][nextdx] = 0;
			q.push({ nextdy, nextdx });
			visited[nextdy][nextdx] = true;
		}
		else {
			if (visited[nextdy][nextdx] == true) {
				clock++;
				break;
			}
			int deleteY = q.front().first;
			int deleteX = q.front().second;
			q.pop();
			visited[deleteY][deleteX] = false;
			visited[nextdy][nextdx] = true;
			q.push({ nextdy,nextdx });
		}
		start_y = nextdy;
		start_x = nextdx;
		clock++;
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	init();
	playgame();
	cout << clock << "\n";
	return 0;
}