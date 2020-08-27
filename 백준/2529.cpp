#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isGameoaver = false;

void dfs(int length, int maxLength, vector<bool> &isVisited, vector<int> &input, vector<string> &v, vector<int> output) {
	
	if (length == maxLength) {
		bool isError = false;
		string getResult = "";
		for (int i = 0; i < length-1; i++) {
			int leftValue = output[i];
			int rightValue = output[i + 1];
			if (v[i] == "<") {
				if (leftValue > rightValue) {
					isError = true;
					break;
				}
			}
			else {
				if (leftValue < rightValue) {
					isError = true;
					break;
				}
			}
		}

		if (isError == true)
			return;

		isGameoaver = true;
		for (int i = 0; i < length; i++)
			getResult += to_string(output[i]);
		cout << getResult << "\n";
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (isVisited[i] == true)
			continue;
		isVisited[i] = true;
		output.push_back(input[i]);
		dfs(length + 1, maxLength, isVisited, input, v, output);
		if (isGameoaver == true)
			return;
		output.pop_back();
		isVisited[i] = false;
	}

}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> v;
	vector<bool> isVisited(10,  false);
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		v.push_back(input);
	}


	vector<int> input;
	for (int i = 9; i >=0 ; i--)
		input.push_back(i);

	vector<int> output;
	dfs(0, n + 1, isVisited, input, v, output);
	
	for (int i = 0; i <= 9; i++)
		isVisited[i] = false;

	sort(input.begin(), input.end());
	isGameoaver = false;
	dfs(0, n + 1, isVisited, input, v, output);

	return 0;
}