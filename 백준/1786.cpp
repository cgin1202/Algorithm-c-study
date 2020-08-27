#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string findWord) {
	int m = findWord.size();
	int j = 0;

	vector<int> pi(m + 1, 0);

	for (int i = 1; i < m; i++) {

		while (j > 0 && findWord[i] != findWord[j])
			j = pi[j - 1];
		if (findWord[i] == findWord[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string s, string p) {
	vector<int> ans;

	vector<int> pi = getPi(p);
	int n = s.size();
	int m = p.size();
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return ans;
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	string input, findWord;
	getline(cin, input);
	getline(cin, findWord);

	vector<int> answer = kmp(input, findWord);
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i]+1 << "\n";
	return 0;
}