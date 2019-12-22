#include <iostream>
#include <string>
using namespace std;

int answer = 1;
int max_length = 0;

void checkEvenPalindrome(string s, int index) {
	int evenlength = 0;
	int idx = 0;
	int left_index = index;
	int right_index = index + 1;

	while (1) {
		if (left_index-idx < 0 || right_index+idx > max_length)
			break;
		if (s[left_index-idx] != s[right_index+idx])
			break;
		evenlength += 2;
		idx++;
	}
	if (evenlength > answer)
		answer = evenlength;
	return;
}

void checkOddPalindrome(string s, int index) {
	int oddlength = 1;
	int idx = 0;
	while (1) {
		if (index - 1-idx < 0 || index + 1+idx > max_length)
			break;
		if (s[index - 1-idx] != s[index + 1+idx])
			break;
		oddlength += 2;
		idx++;
	}
	if (oddlength > answer)
		answer = oddlength;
	return;
}

int solution(string s)
{

	int size = s.size();
	max_length = size-1;
	for (int i = 0; i < size; i++) {
		checkOddPalindrome(s, i);
		checkEvenPalindrome(s, i);
	}
	return answer;
}
int main() {
	int output = solution("abcdcba");
	cout << output << "\n";
	return 0;
}