#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
bool visited[20];

void dfs(int idx, int length) {
	if (length == n) {
		string get_result = "";
		int mo = 0;
		int ja = 0;

		for (int i = 0; i < m; i++) {
			if (visited[i] == true) {
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'i' || arr[i] == 'u')
					mo++;
				else
					ja++;
				get_result += arr[i];
			}
		}

		if (mo >= 1 && ja >= 2) {
			cout << get_result << "\n";
		}
		return;
	}
	for (int i = idx; i < m; i++) {
		if (visited[i] == true)
			continue;
		visited[i] = true;
		dfs(i, length + 1);
		visited[i] = false;
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	dfs(0, 0);
	return 0;
}