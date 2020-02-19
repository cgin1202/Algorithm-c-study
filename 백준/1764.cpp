#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
map<string, int> mm;

void getResult() {
	map<string, int>::iterator it;
	vector<string> result;
	for(it=mm.begin(); it!=mm.end(); it++)
		if (it->second == 2)
			result.push_back(it->first);

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
}
void duplicate(string input) {
	if (mm.find(input) == mm.end())
		mm[input] = 1;
	else
		mm[input]++;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		duplicate(input);
	}

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;
		duplicate(input);
	}

}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	getResult();
	
	return 0;
}