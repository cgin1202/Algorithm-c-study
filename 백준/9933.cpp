#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	map<string, int> checkVisited;
	bool isGameover = false;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		
		if (checkVisited.find(input) == checkVisited.end())
			checkVisited[input] = 1;
		else
			isGameover = true;
		reverse(input.begin(), input.end());

		if (checkVisited.find(input) == checkVisited.end())
			checkVisited[input] = 1;
		else
			isGameover = true;

		if (isGameover == true) {
			cout << input.size() << " " << input[input.size() / 2] << "\n";
			break;
		}
	}
	return 0;
}