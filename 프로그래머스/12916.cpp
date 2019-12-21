#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int left_length = 0;
	int right_length = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p' || s[i] == 'P')
			left_length++;
		if (s[i] == 'y' || s[i] == 'Y')
			right_length++;
	}
	if (left_length == right_length)
		return true;
	else
		return false;
}