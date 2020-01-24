#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, m;
int office[51][51];
vector<pair<int, int>> virus;
bool virus_visited[11];
int virus_length = 0;
vector<pair<int, int>> result;
queue<pair<int, int>> q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool gameVisited[51][51];
int getminResult = 1e9;

int move_virus() {

	int temp_office[51][51];
	int cost_office[51][51];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp_office[i][j] = office[i][j];
			cost_office[i][j] = 0;
		}
	}
	int cost = 0;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int leftnode_x = q.front().first;
			int leftnode_y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int rightnode_x = leftnode_x + dx[k];
				int rightnode_y = leftnode_y + dy[k];
				if (rightnode_x >= 1 && rightnode_y >= 1 && rightnode_x <= n && rightnode_y <= n) {
					if (gameVisited[rightnode_x][rightnode_y] == true)
						continue;
					if (temp_office[rightnode_x][rightnode_y] == 0) {
						gameVisited[rightnode_x][rightnode_y] = true;
						q.push({ rightnode_x, rightnode_y });
						temp_office[rightnode_x][rightnode_y] = 3;
						cost_office[rightnode_x][rightnode_y] = cost_office[leftnode_x][leftnode_y] + 1;
						cost = max(cost, cost_office[rightnode_x][rightnode_y]);
					}

					if (temp_office[rightnode_x][rightnode_y] == 2) {
						gameVisited[rightnode_x][rightnode_y] = true;
						q.push({ rightnode_x, rightnode_y });
						temp_office[rightnode_x][rightnode_y] = 3;
						cost_office[rightnode_x][rightnode_y] = cost_office[leftnode_x][leftnode_y]+1;
					}
				}
			}

		}
	}

	int noVirsu_num = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (temp_office[i][j] == 0)
				noVirsu_num++;
		}
	}
	if (noVirsu_num > 0)
		return -1;
	else
		return cost;
}

void dfs(int index, int length) {
	if (length == m) {

		memset(gameVisited, false, sizeof(gameVisited));
		for (int i = 0; i < length; i++) {
			office[result[i].first][result[i].second] = 3;
			q.push({ result[i].first, result[i].second });
			gameVisited[result[i].first][result[i].second] = true;
		}

		int output = move_virus();
		if (output != -1)
			getminResult = getminResult > output ? output : getminResult;

		for (int i = 0; i < length; i++)
			office[result[i].first][result[i].second] = 2;

		return;
	}

	for (int i = index; i < virus_length; i++) {
		if (virus_visited[i] == true)
			continue;
		virus_visited[i] = true;
		result.push_back({ virus[i].first, virus[i].second });
		dfs(i, length + 1);
		result.pop_back();
		virus_visited[i] = false;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> office[i][j];
			if (office[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}

	virus_length = virus.size();
	dfs(0, 0);

	if (getminResult == 1e9)
		cout << "-1\n";
	else
		cout << getminResult << "\n";
	return 0;
}