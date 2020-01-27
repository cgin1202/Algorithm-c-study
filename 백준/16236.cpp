#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int map[21][21];
bool visited[21][21];
int n;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int fishSize = 2;
int catchCnt = 0;
int getResult = 0;

bool compare(pair<int, int> x, pair<int, int> y) {
	if (x.first < y.first)
		return true;
	if (x.first == y.first)
		return x.second < y.second;
	return false;
}
void gamestart(int i, int j) {
	memset(visited, false, sizeof(visited));
	vector<pair<int, int>> delete_fish;

	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;

	int length = 0;
	bool checkOut = false;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int leftnode_x = q.front().first;
			int leftnode_y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int rightnode_x = leftnode_x + dx[k];
				int rightnode_y = leftnode_y + dy[k];
				if (rightnode_x >= 1 && rightnode_x <= n && rightnode_y >= 1 && rightnode_y <= n) {
					if (visited[rightnode_x][rightnode_y] == true)
						continue;
					if (map[rightnode_x][rightnode_y] > fishSize)
						continue;
					visited[rightnode_x][rightnode_y] = true;
					if (map[rightnode_x][rightnode_y] < fishSize && map[rightnode_x][rightnode_y] != 0) {
						delete_fish.push_back({ rightnode_x, rightnode_y });
						checkOut = true;
					}
					else
						q.push({ rightnode_x, rightnode_y });
				}
			}
		}
		length++;
		if (checkOut == true)
			break;
	}

	int deleteSize = delete_fish.size();
	if (checkOut==false)
		return;
	else {
		catchCnt++;
		getResult += length;
		if (catchCnt == fishSize) {
			fishSize++;
			catchCnt = 0;
		}
		sort(delete_fish.begin(), delete_fish.end(), compare);
		int start_x = delete_fish[0].first;
		int start_y = delete_fish[0].second;
		map[start_x][start_y] = 0;
		gamestart(start_x, start_y);
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;

	int startX = 0;
	int startY = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				startX = i;
				startY = j;
			}
		}
	}
	map[startX][startY] = 0;
	gamestart(startX, startY);

	cout << getResult << "\n";
	return 0;
}