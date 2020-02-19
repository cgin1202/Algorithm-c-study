#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[50][6];
int value[50];
vector<int> input;
bool visited[11];
bool endHorse[4];
int getResult = -1;

void init() {
	input.resize(11);
	for (int i = 0; i < 10; i++)
		cin >> input[i];

	value[0] = 0;
	value[1] = 2;
	value[2] = 4;
	value[3] = 6;
	value[4] = 8;
	value[5] = 10;
	value[6] = 12;
	value[7] = 14;
	value[8] = 16;
	value[9] = 18;
	value[10] = 20;
	value[11] = 22;
	value[12] = 24;
	value[13] = 26;
	value[14] = 28;
	value[15] = 30;
	value[16] = 32;
	value[17] = 34;
	value[18] = 36;
	value[19] = 38;
	value[20] = 40;
	value[21] = 13;
	value[22] = 16;
	value[23] = 19;
	value[24] = 25;
	value[25] = 26;
	value[26] = 27;
	value[27] = 28;
	value[28] = 22;
	value[29] = 24;
	value[30] = 30;
	value[31] = 35;
	value[45] = 0;

	graph[0][1] = 1;
	graph[0][2] = 2;
	graph[0][3] = 3;
	graph[0][4] = 4;
	graph[0][5] = 5;

	graph[1][1] = 2;
	graph[1][2] = 3;
	graph[1][3] = 4;
	graph[1][4] = 5;
	graph[1][5] = 6;

	graph[2][1] = 3;
	graph[2][2] = 4;
	graph[2][3] = 5;
	graph[2][4] = 6;
	graph[2][5] = 7;

	graph[3][1] = 4;
	graph[3][2] = 5;
	graph[3][3] = 6;
	graph[3][4] = 7;
	graph[3][5] = 8;

	graph[4][1] = 5;
	graph[4][2] = 6;
	graph[4][3] = 7;
	graph[4][4] = 8;
	graph[4][5] = 9;

	graph[5][1] = 21;
	graph[5][2] = 22;
	graph[5][3] = 23;
	graph[5][4] = 24;
	graph[5][5] = 30;

	graph[6][1] = 7;
	graph[6][2] = 8;
	graph[6][3] = 9;
	graph[6][4] = 10;
	graph[6][5] = 11;

	graph[7][1] = 8;
	graph[7][2] = 9;
	graph[7][3] = 10;
	graph[7][4] = 11;
	graph[7][5] = 12;

	graph[8][1] = 9;
	graph[8][2] = 10;
	graph[8][3] = 11;
	graph[8][4] = 12;
	graph[8][5] = 13;

	graph[9][1] = 10;
	graph[9][2] = 11;
	graph[9][3] = 12;
	graph[9][4] = 13;
	graph[9][5] = 14;

	graph[10][1] = 28;
	graph[10][2] = 29;
	graph[10][3] = 24;
	graph[10][4] = 30;
	graph[10][5] = 31;

	graph[11][1] = 12;
	graph[11][2] = 13;
	graph[11][3] = 14;
	graph[11][4] = 15;
	graph[11][5] = 16;

	graph[12][1] = 13;
	graph[12][2] = 14;
	graph[12][3] = 15;
	graph[12][4] = 16;
	graph[12][5] = 17;

	graph[13][1] = 14;
	graph[13][2] = 15;
	graph[13][3] = 16;
	graph[13][4] = 17;
	graph[13][5] = 18;

	graph[14][1] = 15;
	graph[14][2] = 16;
	graph[14][3] = 17;
	graph[14][4] = 18;
	graph[14][5] = 19;

	graph[15][1] = 27;
	graph[15][2] = 26;
	graph[15][3] = 25;
	graph[15][4] = 24;
	graph[15][5] = 30;

	graph[16][1] = 17;
	graph[16][2] = 18;
	graph[16][3] = 19;
	graph[16][4] = 20;
	graph[16][5] = 45; // end

	graph[17][1] = 18;
	graph[17][2] = 19;
	graph[17][3] = 20;
	graph[17][4] = 45;
	graph[17][5] = 45;

	graph[18][1] = 19;
	graph[18][2] = 20;
	graph[18][3] = 45;
	graph[18][4] = 45;
	graph[18][5] = 45;

	graph[19][1] = 20;
	graph[19][2] = 45;
	graph[19][3] = 45;
	graph[19][4] = 45;
	graph[19][5] = 45;

	graph[20][1] = 45;
	graph[20][2] = 45;
	graph[20][3] = 45;
	graph[20][4] = 45;
	graph[20][5] = 45;

	graph[21][1] = 22;
	graph[21][2] = 23;
	graph[21][3] = 24;
	graph[21][4] = 30;
	graph[21][5] = 31;

	graph[22][1] = 23;
	graph[22][2] = 24;
	graph[22][3] = 30;
	graph[22][4] = 31;
	graph[22][5] = 20;

	graph[23][1] = 24;
	graph[23][2] = 30;
	graph[23][3] = 31;
	graph[23][4] = 20;
	graph[23][5] = 45;

	graph[24][1] = 30;
	graph[24][2] = 31;
	graph[24][3] = 20;
	graph[24][4] = 45;
	graph[24][5] = 45;

	graph[25][1] = 24;
	graph[25][2] = 30;
	graph[25][3] = 31;
	graph[25][4] = 20;
	graph[25][5] = 45;

	graph[26][1] = 25;
	graph[26][2] = 24;
	graph[26][3] = 30;
	graph[26][4] = 31;
	graph[26][5] = 20;

	graph[27][1] = 26;
	graph[27][2] = 25;
	graph[27][3] = 24;
	graph[27][4] = 30;
	graph[27][5] = 31;

	graph[28][1] = 29;
	graph[28][2] = 24;
	graph[28][3] = 30;
	graph[28][4] = 31;
	graph[28][5] = 20;

	graph[29][1] = 24;
	graph[29][2] = 30;
	graph[29][3] = 31;
	graph[29][4] = 20;
	graph[29][5] = 45;

	graph[30][1] = 31;
	graph[30][2] = 20;
	graph[30][3] = 45;
	graph[30][4] = 45;
	graph[30][5] = 45;

	graph[31][1] = 20;
	graph[31][2] = 45;
	graph[31][3] = 45;
	graph[31][4] = 45;
	graph[31][5] = 45;

	// 0번째에서 주사위 몇번째 돌려서 나오는 위치 저장

	// dfs 돌리면 해결가능해보임

	
}

void dfs(int idx, int horse[], int length, int sum) {
	if (length == 10) {
		getResult = max(getResult, sum);
		return;
	}

	for (int i = idx; i < 10; i++) {
		if (visited[i] == true)
			continue;
		
		int getvalue = input[i];

		for (int k = 0; k < 4; k++) {
			if (endHorse[k] == true)
				continue;
			int nexthorse = graph[horse[k]][getvalue];
			bool impossible = false;

			for (int tk = 0; tk < 4; tk++)
				if (tk != k && nexthorse == horse[tk] && horse[tk]!=45) {
					impossible = true;
				}
			if (nexthorse == 45)
				endHorse[k] = true;

			if (impossible == true)
				continue;
			int temphorse = horse[k];
			horse[k] = nexthorse;
			visited[i] = true;
			dfs(i, horse, length + 1, sum + value[nexthorse]);
			visited[i] = false;
			horse[k] = temphorse;
			if(nexthorse==45)
				endHorse[k] = false;
		}
	}
}
int main() {

	init();
	int horse[4];
	for (int i = 0; i < 4; i++)
		horse[i] = 0;
	dfs(0, horse,0,0);
	cout << getResult << "\n";
	return 0;
}