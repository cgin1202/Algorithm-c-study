#include <iostream>
#include <cstring>

using namespace std;

int n;
int student[100001];
int visted[100001];
bool done[100001];
int cnt = 0;

void dfs(int index) {
	if (done[index] == true || visted[index]==-1)
		return;

	if (visted[index] == 0)
		visted[index] = 1;
	else if (visted[index] == 1) {
		done[index] = true;
		cnt++;
	}
	dfs(student[index]);
	visted[index] = -1;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t > 0) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}
		for (int i = 1; i <= n; i++) {
			if (visted[i] == 0)
				dfs(i);
		}
		
		cout << n - cnt << "\n";
		for (int i = 1; i <= n; i++) {
			student[i] = 0;
			visted[i] = 0;
			done[i] = false;
		}
		cnt = 0;
		t--;
	}
	return 0;
}
