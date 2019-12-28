#include <iostream>

using namespace std;

char map[101][101];

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			scanf(" %c", &map[i][j]);

	int start_left = 1;
	int start_right = 1;

	for (int i = 1; i <= n; i++) {
		bool check = false;
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '#') {
				start_left = i;
				start_right = j;
				check = true;
				break;
			}
		}
		if (check == true)
			break;
	}
	
	int left_length = 0;
	int up_length = 0;
	int right_length = 0;
	int down_length = 0;

	for (int i = start_left; i <= n; i++) {
		if (map[i][start_right] == '#')
			left_length++;
		else
			break;
	}

	for (int i = start_right; i <= m; i++) {
		if (map[start_left][i] == '#')
			up_length++;
		else
			break;
	}

	int max_length = left_length > up_length ? left_length : up_length;
	
	for (int i = start_left; i <= n; i++) {
		if (map[i][start_right + max_length - 1] == '#')
			right_length++;
		else
			break;
	}

	for (int i = start_right; i <= m; i++) {
		if (map[start_left+max_length-1][i] == '#')
			down_length++;
		else
			break;
	}
	
	if (left_length < max_length)
		cout << "LEFT\n";
	if (right_length < max_length)
		cout << "RIGHT\n";
	if (up_length < max_length)
		cout << "UP\n";
	if (down_length < max_length)
		cout << "DOWN\n";
	return 0;
}