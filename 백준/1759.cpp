#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<char> input;
bool visited[20];

void dfs(int index, int length) {
	if (length == n) {

		int ja = 0;
		int mo = 0;

		for (int i = 0; i < m; i++) {
			if (visited[i] == true) {
				if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
					mo++;
				else
					ja++;
			}
		}
		
		if (mo >= 1 && ja >= 2) {
			for (int i = 0; i < m; i++)
				if (visited[i] == true)
					cout << input[i];
			cout << "\n";
		}
		return;
	}

	for (int i = index; i < m; i++) {
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
		char temp;
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end());

	dfs(0, 0);
	
	return 0;
}