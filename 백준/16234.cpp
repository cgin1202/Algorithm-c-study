#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int n, leftvalue, rightvalue;

int map[51][51];
bool visited[51][51];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int bfs(int x, int y) {

	vector<pair<int, int>> group;
	
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = true;
	group.push_back({ x,y });
	while (!q.empty()) {
		int leftnode_x = q.front().first;
		int leftnode_y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int rightnode_x = leftnode_x + dx[k];
			int rightnode_y = leftnode_y + dy[k];
			if (rightnode_x >= 1 && rightnode_x <= n && rightnode_y >= 1 && rightnode_y <= n) {
				if (visited[rightnode_x][rightnode_y] == true)
					continue;
				int value = abs(map[leftnode_x][leftnode_y] - map[rightnode_x][rightnode_y]);
				if (value >= leftvalue && value <= rightvalue) {
					visited[rightnode_x][rightnode_y] = true;
					q.push({ rightnode_x, rightnode_y });
					group.push_back({ rightnode_x, rightnode_y });
				}
			}
		}
	}

	int sum = 0;
	int length = group.size();

	if (length == 1)
		return -1;

	for (int i = 0; i < length; i++) {
		int x = group[i].first;
		int y = group[i].second;
		sum += map[x][y];
	}

	int group_data = sum / length;
	for (int i = 0; i < length; i++) {
		int x = group[i].first;
		int y = group[i].second;
		map[x][y] = group_data;
	}

	return 1;
}
int moveWorld() {
	int getResult = 0;

	while(1){
		bool gameover = true;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i][j] == true)
					continue;
				if (bfs(i, j) == 1) {
					gameover = false;
				}
			}
		}

		if (gameover == true)
			break;
		getResult++;
	}

	return getResult;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> leftvalue >> rightvalue;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];


	cout << moveWorld() << "\n";
	return 0;
}