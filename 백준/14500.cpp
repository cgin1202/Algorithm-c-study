#include <iostream>
#include <algorithm>

using namespace std;

int board[501][501];
int n, m;

int checkTectrino(int x, int y) {

	int tempSum = 0;
	int resultSum = 0;

	// 1
	if (y + 3 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y+1];
		tempSum += board[x][y+2];
		tempSum += board[x][y+3];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;

	//2

	if (x + 3 <= n) {
		tempSum += board[x][y];
		tempSum += board[x+1][y];
		tempSum += board[x+2][y];
		tempSum += board[x+3][y];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 3

	if (x + 1 <= n && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x + 1][y];
		tempSum += board[x][y+1];
		tempSum += board[x + 1][y+1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;

	// 4

	if (x + 2 <= n && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x + 1][y];
		tempSum += board[x+2][y];
		tempSum += board[x + 2][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;

	// 5

	if (x - 2 >= 1 && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y+1];
		tempSum += board[x-1][y+1];
		tempSum += board[x-2][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;



	// 6

	if (x - 1 >= 1 && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y + 1];
		tempSum += board[x][y + 2];
		tempSum += board[x - 1][y + 2];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 7

	if (x +1 <= n && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x+1][y];
		tempSum += board[x+1][y + 1];
		tempSum += board[x+1][y + 2];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 8

	if (x + 1 <= n && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y+1];
		tempSum += board[x][y +2];
		tempSum += board[x + 1][y + 2];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;



	// 9

	if (x + 1 <= n && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x+1][y];
		tempSum += board[x][y + 1];
		tempSum += board[x][y + 2];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 10

	if (x + 2 <= n && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y+1];
		tempSum += board[x+1][y + 1];
		tempSum += board[x+2][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;



	// 11

	if (x + 2 <= n && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y+1];
		tempSum += board[x + 1][y];
		tempSum += board[x + 2][y];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;
	

	// 12

	if (x + 2 <= n && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x+1][y];
		tempSum += board[x + 1][y+1];
		tempSum += board[x + 2][y+1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 13

	if (x-1>=1 && x + 1 <= n && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x + 1][y];
		tempSum += board[x][y + 1];
		tempSum += board[x - 1][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 14

	if (x - 1 >= 1 && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y+1];
		tempSum += board[x-1][y + 1];
		tempSum += board[x - 1][y + 2];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 15

	if (x +1  <= n && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y + 1];
		tempSum += board[x+1][y + 1];
		tempSum += board[x+1][y + 2];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 16

	if (x + 1 <= n && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y + 1];
		tempSum += board[x][y + 2];
		tempSum += board[x + 1][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 17

	if (x + 2 <= n && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x+1][y];
		tempSum += board[x+2][y];
		tempSum += board[x + 1][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 18

	if (x-1>=1 && y + 2 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y + 1];
		tempSum += board[x][y + 2];
		tempSum += board[x - 1][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;


	// 19

	if (x-1>=1 && x+1<=n  && y + 1 <= m) {
		tempSum += board[x][y];
		tempSum += board[x][y+1];
		tempSum += board[x-1][y+1];
		tempSum += board[x + 1][y + 1];
	}

	resultSum = resultSum > tempSum ? resultSum : tempSum;
	tempSum = 0;

	return resultSum;
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

}

int playGame() {
	int getResult = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int output = checkTectrino(i, j);
			getResult = max(getResult, output);
		}
	}
	return getResult;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);


	init();
	cout << playGame() << "\n";

	return 0;
}