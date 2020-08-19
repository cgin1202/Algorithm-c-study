#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int x;
	int y;
	int jump;
	int length;
};
int getShortestLength(int n, int m, vector<vector<int>> &board) {
	
	vector<vector<vector<bool>>> isVisited;
	isVisited.resize(2);
	for (int i = 0; i < 2; i++)
		isVisited[i].resize(n + 1, vector<bool>(m + 1, false));

	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	queue<node> q;
	node inputData;
	inputData.jump = 1;
	inputData.x = 1;
	inputData.y = 1;
	inputData.length = 1;
	q.push(inputData);
	isVisited[1][1][1] = true;
	bool error = true;

	int length = 0;
	int output = -1;

	vector<int> realOutput;

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int presentY = q.front().y;
			int presentX = q.front().x;
			int presentJump = q.front().jump;
			int presentLength = q.front().length;

			q.pop();
			if (presentX == m && presentY == n) {
				error = false;
				realOutput.push_back(presentLength);
				break;
			}
			
			for (int k = 0; k < 4; k++) {
				int nextdy = presentY + dy[k];
				int nextdx = presentX + dx[k];
				if (nextdx > m || nextdy > n || nextdy < 1 || nextdx < 1)
					continue;
				if (board[nextdy][nextdx]==1 && presentJump > 0 && isVisited[presentJump-1][nextdy][nextdx]==false) {
					node tempData;
					tempData.jump = 0;
					tempData.x = nextdx;
					tempData.y = nextdy;
					tempData.length = presentLength+1;
					q.push(tempData);
					isVisited[presentJump-1][nextdy][nextdx] = true;
				}

				if (board[nextdy][nextdx] == 0 && isVisited[presentJump][nextdy][nextdx] == false) {
					node tempData;
					tempData.jump = presentJump;
					tempData.x = nextdx;
					tempData.y = nextdy;
					tempData.length = presentLength + 1;
					q.push(tempData);
					isVisited[presentJump][nextdy][nextdx] = true;
				}
			}


		}
	}

	if (error == true)
		return -1;

	sort(realOutput.begin(), realOutput.end());
	return realOutput[0];
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board;
	board.resize(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			board[i][j + 1] = input[j]-'0';
		}
	}

	cout << getShortestLength(n, m, board) <<"\n";

	return 0;
}