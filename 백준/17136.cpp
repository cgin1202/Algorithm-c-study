#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int minResult = 1e9+1;
vector<pair<int, int>> oneInfo;

bool isGameOver(vector<vector<int>> &board, vector<vector<bool>> &isVisitedBoard) {
	bool error = false;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			if (board[i][j] == 1 && isVisitedBoard[i][j]==false)
				return false;
	return true;
}

vector<bool> getPagePushPossible(int y, int x, vector<vector<int>> &board, vector<vector<bool>> &isVisitedInfo) {
	vector<bool> output(6);

	if (board[y][x] == 1 && isVisitedInfo[y][x] == false)
		output[1] = true;

	bool isNotPossible = false;

	for (int i = y; i <= y + 1; i++) {
		for (int j = x; j <= x + 1; j++) {
			if (i > 10 || j > 10) {
				isNotPossible = true;
				break;
			}

			if (board[i][j] == 0 || isVisitedInfo[i][j] == true) {
				isNotPossible = true;
				break;
			}
		}
		if (isNotPossible == true)
			break;
	}

	if(isNotPossible==false)
		output[2] = true;


	for (int i = y; i <= y + 2; i++) {
		for (int j = x; j <= x + 2; j++) {
			if (i > 10 || j > 10) {
				isNotPossible = true;
				break;
			}

			if (board[i][j] == 0 || isVisitedInfo[i][j] == true) {
				isNotPossible = true;
				break;
			}
		}
		if (isNotPossible == true)
			break;
	}

	if (isNotPossible == false)
		output[3] = true;


	for (int i = y; i <= y + 3; i++) {
		for (int j = x; j <= x + 3; j++) {
			if (i > 10 || j > 10) {
				isNotPossible = true;
				break;
			}

			if (board[i][j] == 0 || isVisitedInfo[i][j] == true) {
				isNotPossible = true;
				break;
			}
		}
		if (isNotPossible == true)
			break;
	}

	if (isNotPossible == false)
		output[4] = true;

	for (int i = y; i <= y + 4; i++) {
		for (int j = x; j <= x + 4; j++) {
			if (i > 10 || j > 10) {
				isNotPossible = true;
				break;
			}

			if (board[i][j] == 0 || isVisitedInfo[i][j] == true) {
				isNotPossible = true;
				break;
			}
		}
		if (isNotPossible == true)
			break;
	}

	if (isNotPossible == false)
		output[5] = true;

	return output;
}

void colorPageMove(int idx, int output, vector<int> &cntPage, vector<vector<int>> &board, vector<vector<bool>> &isVisitedInfo) {

	if (output > minResult)
		return;

	if (isGameOver(board, isVisitedInfo) == true) {
		minResult = min(minResult, output);
		return;
	}

	if (idx >= oneInfo.size())
		return;

	int presentY = oneInfo[idx].first;
	int presentX = oneInfo[idx].second;

	if(isVisitedInfo[presentY][presentX]==true)
		colorPageMove(idx + 1, output, cntPage, board, isVisitedInfo);


	vector<bool> isPushPossible= getPagePushPossible(presentY, presentX, board, isVisitedInfo);

	if (isPushPossible[5] == true && cntPage[5] > 0) {
		cntPage[5]--;
		for (int i = presentY; i <= presentY + 4; i++)
			for (int j = presentX; j <= presentX + 4; j++)
				isVisitedInfo[i][j] = true;
		colorPageMove(idx + 1, output + 1, cntPage, board, isVisitedInfo);
		for (int i = presentY; i <= presentY + 4; i++)
			for (int j = presentX; j <= presentX + 4; j++)
				isVisitedInfo[i][j] = false;
		cntPage[5]++;
	}

	if (isPushPossible[4] == true && cntPage[4] > 0) {
		cntPage[4]--;
		for (int i = presentY; i <= presentY + 3; i++)
			for (int j = presentX; j <= presentX + 3; j++)
				isVisitedInfo[i][j] = true;
		colorPageMove(idx + 1, output + 1, cntPage, board, isVisitedInfo);
		for (int i = presentY; i <= presentY + 3; i++)
			for (int j = presentX; j <= presentX + 3; j++)
				isVisitedInfo[i][j] = false;
		cntPage[4]++;
	}

	if (isPushPossible[3] == true && cntPage[3] > 0) {
		cntPage[3]--;
		for (int i = presentY; i <= presentY + 2; i++)
			for (int j = presentX; j <= presentX + 2; j++)
				isVisitedInfo[i][j] = true;
		colorPageMove(idx + 1, output + 1, cntPage, board, isVisitedInfo);
		for (int i = presentY; i <= presentY + 2; i++)
			for (int j = presentX; j <= presentX + 2; j++)
				isVisitedInfo[i][j] = false;
		cntPage[3]++;
	}

	if (isPushPossible[2] == true && cntPage[2] > 0) {
		cntPage[2]--;
		for (int i = presentY; i <= presentY + 1; i++)
			for (int j = presentX; j <= presentX + 1; j++)
				isVisitedInfo[i][j] = true;

		colorPageMove(idx + 1, output + 1, cntPage, board, isVisitedInfo);
		for (int i = presentY; i <= presentY + 1; i++)
			for (int j = presentX; j <= presentX + 1; j++)
				isVisitedInfo[i][j] = false;

		cntPage[2]++;
	}

	if (isPushPossible[1] == true && cntPage[1] > 0) {
		cntPage[1]--;
		isVisitedInfo[presentY][presentX] = true;
		colorPageMove(idx + 1, output + 1, cntPage, board, isVisitedInfo);
		isVisitedInfo[presentY][presentX] = false;
		cntPage[1]++;
	}


}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<vector<int>> board;
	board.resize(11, vector<int>(11, 0));



	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				oneInfo.push_back({ i,j });
		}
	vector<vector<bool>> isVisitedInfo;
	isVisitedInfo.resize(11, vector<bool>(11, false));

	vector<int> cntPage(6);
	for (int i = 1; i <= 5; i++)
		cntPage[i] = 5;

	colorPageMove(0, 0, cntPage, board, isVisitedInfo);

	if (minResult == 1e9 + 1)
		cout << "-1\n";
	else
		cout << minResult << "\n";

	return 0;
}