#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index = 0;
bool compare(string left, string right) {
	if (left[index] < right[index])
		return true;
	if (left[index] == right[index])
		return left < right;
	return false;
}
vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	index = n;
	sort(strings.begin(), strings.end(), compare);
	answer = strings;
	return answer;
}