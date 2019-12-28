#include <iostream>
#include <string>

using namespace std;

int alpha[30][30];

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			char leftalpha = 'A' + i;
			char rightalpha = 'A' + j;
			
			int diff = rightalpha - leftalpha;
			if (diff >= 0) {
				if (diff > 13) {
					diff = 26 - diff;
				}
				alpha[i][j] = diff;
			}
			else {
				diff = leftalpha - rightalpha;
				if (diff > 13) {
					diff = 26 - diff;
				}
				alpha[i][j] = diff;
			}
		}
	}

	string input;
	cin >> input;

	int get_Result = 0;
	input = 'A' + input;
	for (int i = 0; i < input.size()-1; i++) {
		int leftindex = input[i] - 'A';
		int rightindex = input[i + 1] - 'A';
		get_Result += alpha[leftindex][rightindex];
	}

	cout << get_Result << "\n";
	return 0;
}