#include <iostream>
#include <string>
using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string input;
	cin >> input;

	int size = input.size();
	int answer = 0;

	for (int i = 0; i < size; i++) {
	
		// length 3 check
		if (i + 2 < size) {
			string checkStr = input.substr(i, 3);
			if (checkStr == "dz=") {
				i = i + 2;
				answer++;
				continue;
			}
		}

		// length 2 check
		if (i + 1 < size) {
			string checkStr = input.substr(i, 2);
			if (checkStr == "c=" || checkStr == "c-" || checkStr == "d-" || checkStr == "lj" || checkStr == "nj" || checkStr == "s=" || checkStr == "z=") {
				i = i + 1;
				answer++;
				continue;
			}
		}
		answer++;
	}

	cout << answer << "\n";
	return 0;
}