#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool checkStr(string input) {
	stack<char> s;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(')
			s.push('(');
		else {
			if (s.empty())
				return false;
			s.pop();
		}
	}
	if (!s.empty())
		return false;
	return true;
}

bool checkStr2(string input) {
	int left = 0;
	int right = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(')
			left++;
		else
			right++;
	}
	if (left == right)
		return true;
	else
		return false;
}
string changeStr(string input) {
	if (input == "")
		return "";

	if (checkStr(input) == true)
		return input;

	int length = 2;
	int size = input.size();
	for (int i = 0; i < size; i++) {
		if (length > size)
			break;
		string leftStr = input.substr(0, length);
		string rightStr = input.substr(length);

		if (checkStr2(leftStr) == false  || checkStr2(rightStr) == false) {
			length += 2;
			continue;
		}

		if (checkStr(leftStr) == true)
			return leftStr + changeStr(rightStr);
		else {
			string output = "(";
			output += changeStr(rightStr);
			output += ")";

			leftStr.erase(0, 1);
			leftStr.pop_back();

			for (int k = 0; k < leftStr.size(); k++) {
				if (leftStr[k] == '(')
					leftStr[k] = ')';
				else
					leftStr[k] = '(';
			}

			output += leftStr;
			return output;

		}
		length=length+2;
	}
}
string solution(string p) {
	string answer = "";

	answer = changeStr(p);
	return answer;
}