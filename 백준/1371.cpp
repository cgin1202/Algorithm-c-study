#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string input;
	
	vector<int> count(27, 0);
	int maxCount = 0;
	while (1) {
		getline(cin, input);
		if (cin.eof() == true)
			break;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] >= 'a' && input[i] <= 'z') {
				count[input[i] - 'a']++;
				maxCount = max(maxCount, count[input[i] - 'a']);
			}
		}
	}

	for (int i = 0; i < 27; i++)
		if (count[i] == maxCount)
			cout << char(i + 'a');
	cout << "\n";


	return 0;
}