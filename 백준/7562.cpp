#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int startX, startY;
int endX, endY;

int calcTimeFastestWay(int startX, int startY, int endX, int endY, int n, vector<vector<int>> &graph, vector<vector<bool>> &isVisited) {
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	isVisited[startY][startX] = true;
	
	int dx[] = {2,1, 2, 1, -1, -2, -1, -2};
	int dy[] = {-1, -2,1, 2, -2, -1, 2, 1};

	int length = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int presentY = q.front().first;
			int presentX = q.front().second;
			q.pop();

			if (presentX == endX && presentY == endY)
				return length;

			for (int k = 0; k < 8; k++) {
				int nextdy = presentY + dy[k];
				int nextdx = presentX + dx[k];

				if (nextdx<1 || nextdy <1 || nextdx>n || nextdy>n)
					continue;
				if (isVisited[nextdy][nextdx] == true)
					continue;
				q.push({ nextdy, nextdx });
				isVisited[nextdy][nextdx] = true;
			}

		}
		length++;
	}
	return -1;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int tk;
	cin >> tk;

	while (tk > 0) {
		
		vector<vector<int>> graph;
		vector<vector<bool>> isVisited;
		int n;
		cin >> n;

		graph.resize(n + 1, vector<int>(n + 1, 0));
		isVisited.resize(n + 1, vector<bool>(n + 1, false));

		int startX, startY;
		int endX, endY;

		cin >> startX >> startY;
		cin >> endX >> endY;

		cout << calcTimeFastestWay(startX+1, startY+1, endX+1, endY+1, n, graph, isVisited) << "\n";
		tk--;
	}

	return 0;
}