#include <iostream>
#include <vector>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > member;
int totalData = 0;
bool visited[21];
bool tempVisted[11];
vector<int> tempData;
int getResult = 1e9;
int first = 1;

void dfs2(int length, int n, vector<int> input) {
	if (length == 2) {
		int tempSum = 0;
		int leftIndex = tempData[0];
		int rightIndex = tempData[1];
		tempSum += member[leftIndex][rightIndex];
		totalData += tempSum;
		return;
	}
	if (length > 2)
		return;
	for (int i = 0; i < n; i++) {
		if (tempVisted[i] == true)
			continue;
		tempVisted[i] = true;
		tempData.push_back(input[i]);
		dfs2(length + 1, n, input);
		tempData.pop_back();
		tempVisted[i] = false;
	}
}

int getTotalAdd(vector<int> input) {
	totalData = 0;
	memset(tempVisted, false, sizeof(tempVisted));
	tempData.clear();

	dfs2(0, input.size(), input);
	return totalData;
}

void compareDiff(vector<int> a, vector<int> b) {
	int aSum = getTotalAdd(a);
	int bSum = getTotalAdd(b);
	int output = abs(aSum - bSum);
	getResult = min(getResult, output);
}

void dfs(int idx, int length) {
	if (length == n / 2) {
		vector<int> teamA;
		vector<int> teamB;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == true)
				teamA.push_back(i);
			else
				teamB.push_back(i);
		}

		compareDiff(teamA, teamB);
		return;
	}
	if (length > n / 2)
		return;

	for (int i = idx; i <= n; i++) {
		if (visited[i] == true)
			continue;
		visited[i] = true;
		dfs(i, length + 1);
		visited[i] = false;
	}
}

void init() {
	cin >> n;
	member.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> member[i][j];
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	init();
	dfs(1, 0);
	cout << getResult << "\n";
	return 0;
}