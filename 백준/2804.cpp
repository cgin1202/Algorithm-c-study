#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string left, right;
	cin >> left >> right;

	int leftIndex = 0;
	int rightIndex = 0;

	bool isFinished = false;
	for (int i = 0; i < left.size(); i++) {
		for(int j=0; j<right.size(); j++)
			if (left[i] == right[j]) {
				leftIndex = i;
				rightIndex = j;
				isFinished = true;
				break;
			}
		if (isFinished == true)
			break;
	}

	vector<vector<char>> output;
	output.resize(right.size(), vector<char>(left.size(), '.'));

	for (int i = 0; i < left.size(); i++)
		output[rightIndex][i] = left[i];

	for (int i = 0; i < right.size(); i++)
		output[i][leftIndex] = right[i];

	for (int i = 0; i < right.size(); i++) {
		for (int j = 0; j < left.size(); j++)
			cout << output[i][j];
		cout << "\n";
	}
	return 0;
}