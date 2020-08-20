#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void searchGroup(int index, vector<int>& node, vector<bool>& isVisited, vector<bool>& isDone) {
	int nextNum = node[index];
	isVisited[index] = true;
	if (isVisited[nextNum] == false)
		searchGroup(nextNum, node, isVisited, isDone);
	else {
		if (isDone[nextNum] == false) {
			for (int i = nextNum; i != index; i = node[i])
				cnt++;
			cnt++;
		}
	}
	isDone[index] = true;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int tk;
	cin >> tk;

	while (tk > 0) {
		
		int n;
		cin >> n;

		vector<int> node;
		node.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> node[i];

		vector<bool> isVisited(n+1, false);
		vector<bool> isDone(n+1, false);

		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (isVisited[i] == false)
				searchGroup(i, node, isVisited, isDone);

		cout << n - cnt << "\n";
		tk--;
	}

	return 0;
}