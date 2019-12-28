#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int index = 1;
	while (1) {
		string input;
		getline(cin,input);

		if (input == "Was it a cat I saw?")
			break;

		string get_result = "";
		for (int i = 0; i < input.size(); i++) {
			get_result += input[i];
			i = i + index;
		}
		cout << get_result << "\n";
		index++;
	}


	return 0;
}