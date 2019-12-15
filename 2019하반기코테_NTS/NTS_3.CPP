#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check_correct(string input) {
	stack<char> s;
	int input_length = input.size();
	for (int i = 0; i < input_length; i++) {
		if (!s.empty()) {
			char top_value = s.top();
			if ((top_value == '(' && input[i] == ')') || (top_value == '{' && input[i] == '}') || (top_value == '[' && input[i] == ']')) {
				s.pop();
			}
			else if (top_value == '(' && (input[i] == '{' || input[i] == '[' || input[i]=='(')) {
				return false;
			}
			else if (top_value == '{' && (input[i] == '[' || input[i]=='{')) {
				return false;
			}
			else if (top_value == '[' && input[i] == '[' ) {
				return false;
			}
			else if(input[i]=='(' || input[i]=='{' || input[i]=='[' || input[i]==')' || input[i]=='}' || input[i]==']')
				s.push(input[i]);
		}
		else {
			if (input[i] == '(' || input[i] == '{' || input[i] == '[')
				s.push(input[i]);
			else if(input[i]==')' || input[i]=='}' || input[i]==']')
				return false;
		}
	}
	if (s.size() > 0)
		return false;
	return true;
}
bool solution(string input) {
	bool answer = check_correct(input);
	return answer;
}