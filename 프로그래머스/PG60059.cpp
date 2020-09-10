#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isCheckCorrect(int x, int y, int m, vector<vector<int>> key, vector<vector<int>> board) {
	int n = key.size();

	for (int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
			board[i][j] += key[i - y][j - x];

	for (int i = n - 1; i < n + m - 1; i++) {
		for (int j = n - 1; j < n + m - 1; j++) {
			if (board[i][j] != 1)
				return false;
		}
	}
	return true;
}

void rotate(vector<vector<int>> &key) {
	int n = key.size();
	vector<vector<int>> output;
	output.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			output[j][n-i-1] = key[i][j];
	key = output;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;

	int n = key.size();
	int m = lock.size();
	int boardSize = m + (n - 1) * 2;
	vector<vector<int>> board;
	board.resize(boardSize, vector<int>(boardSize, 0));

	// startpoint : n,n

	for (int i = n-1; i < n + m-1; i++)
		for (int j = n-1; j < n + m-1; j++)
			board[i][j] = lock[i - n+1][j - n+1];
	
	/*
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
	*/


	

	for (int i = 0; i < boardSize - n + 1; i++) {
		for (int j = 0; j < boardSize - n + 1; j++) {
			
			//check
			for (int k = 0; k < 4; k++) {
				rotate(key);
				/*
				for (int x = 0; x < n; x++) {
					for (int y = 0; y < n; y++)
						cout << key[x][y] << " ";
					cout << "\n";
				}
				cout << "\n";
				*/
				if (isCheckCorrect(j, i, m, key, board) == true)
					return true;
			}
		}
	}
	return false;
}
