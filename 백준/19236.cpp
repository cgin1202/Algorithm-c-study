#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 다음 좌표로 이동하기 위해 dir 값

pair<int, int> getDirectionXY(int presentDir) {
	if (presentDir == 1)
		return { -1,0 };
	else if (presentDir == 2)
		return { -1,-1 };
	else if (presentDir == 3)
		return { 0,-1 };
	else if (presentDir == 4)
		return { 1,-1 };
	else if (presentDir == 5)
		return { 1,0 };
	else if (presentDir == 6)
		return { 1,1 };
	else if (presentDir == 7)
		return { 0,1 };
	else
		return { -1,1 };
}

// 다음 위치 결정 함수 (45도 회전)

int getNextDir(int presentDir) {
	int nextDir = presentDir+1;
	if (nextDir > 8)
		nextDir = 1;
	return nextDir;
}

// input

void init(vector<vector<pair<int, int>>> &board, vector<pair<int, int>> &fishNumLocation, vector<int> & fishNumDir) {
	board.resize(5, vector<pair<int, int>>(5, { 0,0 }));
	fishNumLocation.resize(17);
	fishNumDir.resize(17);

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			int fishNum, dir;
			cin >> fishNum >> dir;
			board[i][j] = { fishNum, dir };
			fishNumLocation[fishNum].first = i;
			fishNumLocation[fishNum].second = j;
			fishNumDir[fishNum] = dir;
		}
	}
}

int maxOutput = 0;

void sharkSituaion(int sharkSituationY, int sharkSituationX, int sharkDir, int output, vector<bool> visitedFishNum, vector<vector<pair<int, int>>> board, vector<pair<int, int>> fishNumLocation, vector<int> fishNumDir) {

	while (1) {

		// 고기들 움직이기

		for (int i = 1; i <= 16; i++) {
			// 잡아먹힌 고기는 pass
			if (visitedFishNum[i] == true)
				continue;

			bool isPossibleMove = false;
			int presentDir = fishNumDir[i];

			int fishMoveY = 0;
			int fishMoveX = 0;

			for (int k = 0; k < 8; k++) {
				int nextDir = 0;
				if (k == 0)
					nextDir = presentDir;
				else
					nextDir = getNextDir(presentDir);

				int nextdy = fishNumLocation[i].first + getDirectionXY(nextDir).first;
				int nextdx = fishNumLocation[i].second + getDirectionXY(nextDir).second;

				if (nextdy >= 1 && nextdx >= 1 && nextdx <= 4 && nextdy <= 4) {
					// 상어가 아닌 경우
					if (board[nextdy][nextdx].first != 100) {
						presentDir = nextDir;
						fishMoveY = nextdy;
						fishMoveX = nextdx;
						isPossibleMove = true;
						break;
					}
				}
				presentDir = nextDir;
			}

			// 해당 물고기 이동
			if (isPossibleMove == true) {

				// presentDir

				int presentFishNum = i;
				int presentY = fishNumLocation[i].first;
				int presentX = fishNumLocation[i].second;

				int nextdy = presentY + getDirectionXY(presentDir).first;
				int nextdx = presentX + getDirectionXY(presentDir).second;

				int nextFishNum = board[nextdy][nextdx].first;
				int nextFishDir = board[nextdy][nextdx].second;

				//위치는 변경 but 방향은 변경 x (이동 당하는 물고기)
				fishNumLocation[nextFishNum].first = presentY;
				fishNumLocation[nextFishNum].second = presentX;
				board[presentY][presentX].first = nextFishNum;
				board[presentY][presentX].second = nextFishDir;

				// 위치는 변경 but 방향은 변경될 수 있음 (이동 시키는 물고기)
				fishNumLocation[presentFishNum].first = nextdy;
				fishNumLocation[presentFishNum].second = nextdx;
				board[nextdy][nextdx].first = presentFishNum;
				board[nextdy][nextdx].second = presentDir;
				fishNumDir[presentFishNum] = presentDir;
			}
		}

		// 상어 움직이기
		/*
		cout << "\n\n";
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++)
				cout << board[i][j].first << " " << board[i][j].second << "\t";
			cout << "\n";
		}*/


		// 상어가 움직일 수 있는 좌표 구하기

		vector<pair<int, int>> sharkLocation;
		int cnt = 0;
		int multiTemp = 1;

		while (1) {
			int nextdy = sharkSituationY + (getDirectionXY(sharkDir).first* multiTemp);
			int nextdx = sharkSituationX + (getDirectionXY(sharkDir).second* multiTemp);
			if (nextdy < 1 || nextdx < 1 || nextdy>4 || nextdx>4)
				break;
			// 물고기가 있는 경우
			if (board[nextdy][nextdx].first != 0) {
				sharkLocation.push_back({ nextdy, nextdx });
				cnt++;
			}
			multiTemp++;
		}

		// 상어가 움직이지 못할 경우 stop

		if (cnt == 0) {
			maxOutput = max(maxOutput, output);
			return;
		}
		else {

			// 상어가 움직인 좌표 각각에 대해서 재귀함수 돌리기
			board[sharkSituationY][sharkSituationX].first = 0;
			for (int i = 0; i < sharkLocation.size(); i++) {
				int nextdy = sharkLocation[i].first;
				int nextdx = sharkLocation[i].second;

				// 상어의 현재 좌표에 대해서는 0을 넣어야 한다.

				int fishNum = board[nextdy][nextdx].first;
				int fishDir = board[nextdy][nextdx].second;
				board[nextdy][nextdx].first = 100;
				visitedFishNum[fishNum] = true;
				sharkSituaion(nextdy, nextdx, fishDir, output + fishNum, visitedFishNum, board, fishNumLocation, fishNumDir);
				visitedFishNum[fishNum] = false;
				board[nextdy][nextdx].first = fishNum;
			}
			return;
		}

	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	// 판때기
	vector<vector<pair<int, int>>> board;

	// 물고기 NUM 위치
	vector<pair<int, int>> fishNumLocation;

	// 물고기 NUM 방향
	vector<int> fishNumDir;

	// 잡아먹힌 물고기 NUM 에 대해서 재방문 하지 않도록 처리
	vector<bool> visitedFishNum(17);
	for (int i = 1; i <= 16; i++)
		visitedFishNum[i] = false;

	init(board, fishNumLocation, fishNumDir);
	
	// 결과값 : 상어가 먹을 수 있는 물고기 번호의 합의 최대값 output

	// 상어 위치를 {0,0}로 이동하고 0,0에 있는 물고기 정보를 상어에 매핑


	int sharkSituationY = 1;
	int sharkSituationX = 1;

	int zeroFishNum = board[1][1].first;
	int zeroFishDir = board[1][1].second;

	// 100 : 상어 Num
	board[1][1].first = 100;

	// 0 : 비어있다! (상어가 지나가는 곳은 0으로 채워지겠지?)


	// {1,1}에 있는 고기는 잡아먹힘
	visitedFishNum[zeroFishNum] = true;
	
	// zeroFishNum;
	sharkSituaion(1, 1, zeroFishDir, zeroFishNum, visitedFishNum, board, fishNumLocation, fishNumDir);
	cout << maxOutput << "\n";
	return 0;
}