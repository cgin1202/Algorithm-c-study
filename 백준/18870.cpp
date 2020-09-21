#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> v2(n);
	map<int, int> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v2[i] = v[i];
	}

	sort(v2.begin(), v2.end());
	int num = 0;

	for (int i = 0; i < n; i++) {
		if (m.find(v2[i]) == m.end()) {
			m[v2[i]] = num;
			num++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << m[v[i]] << " ";
	cout << "\n";

	return 0;
}