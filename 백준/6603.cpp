#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;
bool visited[20];
vector<int> output;

void dfs(int idx, int length) {	
	if (length == 6) {
		for (int i = 0; i < output.size(); i++)
			cout << output[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		if (visited[i] == true)
			continue;
		visited[i] = true;
		output.push_back(v[i]);
		dfs(i, length + 1);
		output.pop_back();
		visited[i] = false;
	}
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		v.clear();
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			v.push_back(input);
		}

		dfs(0, 0);
		cout << "\n";

	}
	return 0;
}