#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void getPermutation(map<string, int> &isCheckDuplicate, int index, int length, int n, int m, vector<int> output, vector<int> &input, vector<bool> &isVisitedIndex) {
	if (length == m) {
		string checkOutput = "";
		
		for (int i = 0; i < m; i++)
			checkOutput += (to_string(output[i])+" ");
		if (isCheckDuplicate.find(checkOutput) == isCheckDuplicate.end()) {
			cout << checkOutput << "\n";
			isCheckDuplicate[checkOutput] = 1;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isVisitedIndex[i] == true)
			continue;
		output.push_back(input[i]);
		isVisitedIndex[i] = true;
		getPermutation(isCheckDuplicate, i, length + 1, n, m, output, input, isVisitedIndex);
		isVisitedIndex[i] = false;
		output.pop_back();
	}

}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];

	vector<bool> isVisitedNumber(10001);
	vector<bool> isVisitedIndex(n);

	for (int i = 0; i < n; i++)
		isVisitedIndex[i] = false;

	for (int i = 0; i <= 10000; i++)
		isVisitedNumber[i] = false;

	sort(input.begin(), input.end());

	map<string, int> isCheckDuplicate;
	getPermutation(isCheckDuplicate, 0, 0, n, m, {}, input, isVisitedIndex);

	return 0;
}