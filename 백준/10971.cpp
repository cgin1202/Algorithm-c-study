#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int map[11][11];
bool visited[11];
int minValue = 1e9;
int resultValue = 1e9;
int startIndex = 0;

void dfs(int present, int length, int sum) {
	if (length == n-1) {
		if (map[present][startIndex] == 0)
			sum = 1e9;
		else
			sum += map[present][startIndex];
		minValue = min(minValue, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == true)
			continue;
		int next = i;
		int value = map[present][next];
		if (value == 0)
			continue;

		visited[i] = true;
		dfs(next, length + 1, sum + value);
		visited[i] = false;
	}
}

int getResult() {
	minValue = 1e9;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		startIndex = i;
		visited[i] = true;
		dfs(i, 0, 0);
	}
	resultValue = min(minValue, resultValue);
	return resultValue;
}
void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];


}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);


	init();
	cout << getResult() << "\n";
	return 0;
}