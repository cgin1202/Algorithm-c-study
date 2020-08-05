#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
	int value;
	int x;
	int y;
};

struct compare {
	bool operator()(node x, node y) {
		if (x.value < y.value)
			return true;
		else
			return false;
	}
};

int getShortestLength(int n, vector<vector<int>> &board) {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ 0, 1, 1 });

	int totalN = n * n;
	vector<int> dist(totalN + 1);
	for (int i = 1; i <= totalN; i++)
		dist[i] = 1e9 + 1;
	dist[1] = 0;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	while (!pq.empty()) {

		int presentValue = -pq.top().value;
		int presentX = pq.top().x;
		int presentY = pq.top().y;
		pq.pop();

		for (int k = 0; k < 4; k++) {
			int nextdx = dx[k] + presentX;
			int nextdy = dy[k] + presentY;
			if (nextdx<1 || nextdy<1 || nextdx>n || nextdy>n)
				continue;
			int nodeNum = (nextdy - 1) * n + nextdx;
			int nextValue = board[nextdy][nextdx];
			if (dist[nodeNum] > nextValue + presentValue) {
				dist[nodeNum] = nextValue + presentValue;
				pq.push({ -dist[nodeNum], nextdx, nextdy });
			}
		}

	}
	dist[totalN] = dist[totalN] + board[1][1];
	return dist[totalN];
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int idx = 1;

	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		vector<vector<int>> board;
		board.resize(n + 1, vector<int>(n + 1, 0));

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> board[i][j];
		cout << "Problem " << idx << ":" << " ";
		cout << getShortestLength(n, board) << "\n";
		idx++;
	}
	return 0;
}