#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
bool visited[51];
vector<int> v;
int max_result = 0;
int max_length = 0;
string input;

void dfs(int index) {
	if (index == max_length) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		exit(0);
	}

	string temp = "";

	for (int i = index; i <= index + 1; i++) {
		temp += input[i];
		int temp_int = stoi(temp);

		if (visited[temp_int] == true)
			continue;
		if (temp_int > n)
			continue;
		visited[temp_int] = true;
		v.push_back(temp_int);
		dfs(i+1);
		v.pop_back();
		visited[temp_int] = false;

	}
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> input;

	int size = input.size();
	max_length = size;
	if (size <= 9)
		n = size;
	else {
		n = 9;
		size = size - 9;
		n += (size / 2);
	}
	dfs(0);

	return 0;
}