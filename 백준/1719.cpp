#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int n, k;
vector<pair<int, int>> node[201];
vector<int> dist(201);
vector<int> track(201);

void get_shortpath(int index) {
	for (int i = 1; i <= n; i++)
		track[i] = i;
	for (int i = 1; i <= n; i++)
		dist[i] = INT_MAX;

	dist[index] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, index });

	while (!pq.empty()) {
		int leftvalue = -pq.top().first;
		int leftnode = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[leftnode].size(); i++) {
			int rightvalue = node[leftnode][i].first;
			int rightnode = node[leftnode][i].second;
			if (dist[rightnode] > dist[leftnode] + rightvalue) {
				track[rightnode] = leftnode;
				dist[rightnode] = dist[leftnode] + rightvalue;
				pq.push({ -dist[rightnode], rightnode });
			}
		}

	}
}

int main() {
	
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int left, right, value;
		cin >> left >> right >> value;
		node[left].push_back({ value, right });
		node[right].push_back({ value, left });
	}

	for (int i = 1; i <= n; i++) {
		get_shortpath(i);
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else {
				int temp = j;
				while (track[temp] != i)
					temp = track[temp];
				cout << temp << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}