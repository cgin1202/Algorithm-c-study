#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	
	string input, bomb;
	getline(cin, input);
	getline(cin, bomb);

	string output = "";
	int outputSize = 0;

	int bombSize = bomb.size();
	int getResult = 0;

	for (int i = 0; i < input.size(); i++) {
		output += input[i];
		outputSize++;

		if (input[i] == bomb[bombSize - 1]) {
			if (outputSize < bombSize)
				continue;

			string tempOutput = output.substr(output.size() - bombSize, bombSize);
			if (tempOutput == bomb) {

				for (int k = 0; k < bombSize; k++)
					output.clear();
				outputSize = 0;
				getResult++;
			}
		}
	}
	cout << getResult << "\n";
	return 0;
}