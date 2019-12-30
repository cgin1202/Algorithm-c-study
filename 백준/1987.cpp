#include <iostream>
#include <string>

using namespace std;

int n, m;
char map[21][21];
int get_result = 0;
int alphabet[26] = { 0 };

void dfs(int left, int right, int length) {
	if (length > get_result)
		get_result = length;

	
	if (left - 1 >= 0) {
		int idx = map[left - 1][right] - 'A';
		if (alphabet[idx] == 0) {
			alphabet[idx]++;
			dfs(left - 1, right, length+1);
			alphabet[idx]--;
		}
	}
	if (right - 1 >= 0) {
		int idx = map[left][right-1] - 'A';
		if (alphabet[idx] == 0) {
			alphabet[idx]++;
			dfs(left, right-1, length + 1);
			alphabet[idx]--;
		}
	}
	if (left + 1 < n) {
		int idx = map[left + 1][right] - 'A';
		if (alphabet[idx] == 0) {
			alphabet[idx]++;
			dfs(left + 1, right, length + 1);
			alphabet[idx]--;
		}
	}
	if (right + 1 < m) {
		int idx = map[left][right+1] - 'A';
		if (alphabet[idx] == 0) {
			alphabet[idx]++;
			dfs(left, right+1, length + 1);
			alphabet[idx]--;
		}
	}
	return;
}
int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			scanf(" %c", &map[i][j]);

	char temp = map[0][0];
	string start = "";
	start += temp;
	alphabet[map[0][0]-'A']++;
	dfs(0, 0, 1);

	cout << get_result << "\n";
	return 0;
}