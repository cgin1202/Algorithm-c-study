#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, m;

int input[10][10];
bool visited[100];
vector<pair<int, int>> output;
int maxResult = 0;
vector<pair<int, int>> zeroInput;
int input_length = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0,0 };
int temp_input[10][10];
queue<pair<int, int>> pq;
int getSavezone() {
	// 바이러스에 대해서 bfs 전부 돌리고 전체 map에 대해서 0의 개수만 세주면 된다.

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp_input[i][j] = input[i][j];


	queue<pair<int, int>> q(pq);

	while (!q.empty()) {
		int leftnode_x = q.front().first;
		int leftnode_y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int rightnode_x = leftnode_x + dx[k];
			int rightnode_y = leftnode_y + dy[k];
			if (rightnode_x >= 0 && rightnode_x < n && rightnode_y >= 0 && rightnode_y < m) {
				if (temp_input[rightnode_x][rightnode_y] == 0) {
					temp_input[rightnode_x][rightnode_y] = 2;
					q.push({ rightnode_x, rightnode_y });
				}
			}
		}
	}

	int savezoneNum = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (temp_input[i][j] == 0)
				savezoneNum++;

	return savezoneNum;
}

void dfs(int index, int length) {
	if (length == 3) {

		// 64 combination 3 (모든 경우의 수를 다 check)

		for (int i = 0; i < length; i++)
			input[output[i].first][output[i].second] = 1;

		int value = getSavezone();

		maxResult = maxResult > value ? maxResult : value;

		for (int i = 0; i < length; i++)
			input[output[i].first][output[i].second] = 0;

		return;
	}

	for (int i = index; i < input_length; i++) {
		if (visited[i] == true)
			continue;
		visited[i] = true;
		output.push_back({ zeroInput[i].first, zeroInput[i].second });
		dfs(i, length + 1);
		output.pop_back();
		visited[i] = false;
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> input[i][j];
			if(input[i][j]==0)
				zeroInput.push_back({ i,j });
		}

	input_length = zeroInput.size();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (input[i][j] == 2)
				pq.push({ i,j });

	dfs(0, 0);
	
	cout << maxResult << "\n";

	return 0;
}