#include <iostream>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string input, bomb;
	cin >> input >> bomb;

	int bombSize = bomb.size();

	string output = "";
	int outputSize = 0;
	for (int i = 0; i < input.size(); i++) {
		output += input[i];
		outputSize++;

		if (input[i] == bomb[bombSize - 1]) {
			if (outputSize < bombSize)
				continue;
			string tempOutput = output.substr(output.size() - bombSize, bombSize);
			//cout << "test : " << tempOutput << "\n";
			
			if (tempOutput == bomb) {
				outputSize -= bombSize;
				for (int k = 0; k < bombSize; k++)
					output.pop_back();
			}
		}
	}
	if (output.size() == 0)
		cout << "FRULA\n";
	else
		cout << output << "\n";
	return 0;
}