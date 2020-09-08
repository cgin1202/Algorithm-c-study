#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	vector<vector<char>> gameBoard;
	gameBoard.resize(m + 1, vector<char>(n + 1));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < board[i].size(); j++)
			gameBoard[i][j] = board[i][j];


	while (1) {

		vector<pair<int, int>> deleteIndex;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (gameBoard[i][j] == gameBoard[i][j + 1] && gameBoard[i][j] == gameBoard[i + 1][j] && gameBoard[i][j] == gameBoard[i + 1][j + 1]) {
					if (gameBoard[i][j] == '.')
						continue;
					deleteIndex.push_back({ i, j });
					deleteIndex.push_back({ i + 1, j });
					deleteIndex.push_back({ i, j + 1 });
					deleteIndex.push_back({ i + 1, j + 1 });
				}
			}
		}

		if (deleteIndex.size() == 0)
			break;

		vector<vector<bool>> isVisited;
		isVisited.resize(m + 1, vector<bool>(n + 1, false));

		for (int i = 0; i < deleteIndex.size(); i++) {
			int leftIndex = deleteIndex[i].first;
			int rightIndex = deleteIndex[i].second;
			if (isVisited[leftIndex][rightIndex] == true)
				continue;
			answer++;
			isVisited[leftIndex][rightIndex] = true;
			gameBoard[leftIndex][rightIndex] = '.';
		}


		// move
		for (int j = 0; j < n; j++) {
			queue<char> q;
			for (int i = m - 1; i >= 0; i--)
				q.push(gameBoard[i][j]);

			queue<char> result;
			for (int i = 0; i < m; i++) {
				char frontQ = q.front();
				q.pop();
				if (frontQ != '.')
					result.push(frontQ);
			}

			int gap = m - result.size();
			for (int i = 0; i < gap; i++)
				result.push('.');

			for (int i = m - 1; i >= 0; i--) {
				char frontQ = result.front();
				result.pop();
				gameBoard[i][j] = frontQ;
			}
		}

	}

	return answer;
}