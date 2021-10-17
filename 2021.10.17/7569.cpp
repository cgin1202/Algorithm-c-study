#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	int h;
	int y;
	int x;
};

int dh[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dx[] = {1,-1,0,0,0,0};
int maxH = 0;
int maxY = 0;
int maxX = 0;


int searchTomato(vector<vector<vector<int>>> &board, vector<vector<vector<bool>>> &isVisited, queue<node> &tomato) {
	
	int length = 0;

	while (!tomato.empty()) {
		int size = tomato.size();
		bool isCheck = false;

		for (int i = 0; i < size; i++) {
			int h = tomato.front().h;
			int y = tomato.front().y;
			int x = tomato.front().x;
			tomato.pop();

			for (int k = 0; k < 6; k++) {
				int nextdh = h + dh[k];
				int nextdy = y + dy[k];
				int nextdx = x + dx[k];
				
				if (nextdh < 0 || nextdy < 0 || nextdx < 0 || nextdh >= maxH || nextdy >= maxY || nextdx >= maxX)
					continue;
				if (isVisited[nextdh][nextdy][nextdx] == true)
					continue;
				if (board[nextdh][nextdy][nextdx] != 0)
					continue;

				isCheck = true;
				tomato.push({ nextdh, nextdy, nextdx });
				isVisited[nextdh][nextdy][nextdx] = true;
				board[nextdh][nextdy][nextdx] = 1;
			}
		}
		if(isCheck==true)
			length++;
	}


	for (int i = 0; i < maxH; i++) {
		for (int j = 0; j < maxY; j++) {
			for (int k = 0; k < maxX; k++) {
				if (board[i][j][k] == 0)
					length = -1;
			}
		}
	}

	return length;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);


	int x, y, h;
	cin >> x >> y >> h;
	maxH = h;
	maxY = y;
	maxX = x;

	vector<vector<vector<int>>> board;
	vector<vector<vector<bool>>> isVisited;
	queue<node> tomato;

	board.resize(h);
	isVisited.resize(h);
	for (int i = 0; i < h; i++) {
		board[i].resize(y);
		isVisited[i].resize(y);
		for (int j = 0; j < y; j++) {
			board[i][j].resize(x);
			isVisited[i][j].resize(x, false);
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				int data;
				cin >> data;
				board[i][j][k] = data;

				if (data == 1) {
					tomato.push({ i,j,k });
					isVisited[i][j][k] = true;
				}
			}
		}
	}

	int answer = searchTomato(board, isVisited, tomato);
	cout << answer << "\n";

	return 0;
}
