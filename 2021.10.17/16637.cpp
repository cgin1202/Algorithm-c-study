#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maxSize = 0;

vector<string> input;

// make gualho
void makeGualho(int i, string str, string makeStr) {

	// pos = end point
	if (i >= maxSize) {
		//cout << makeStr << "\n";
		input.push_back(makeStr);
		return;
	}

	// pos+2 == end point
	if (i+2 >= maxSize) {
		//cout << makeStr+str[i]+str[i+1] << "\n";
		input.push_back(makeStr+str[i]+str[i+1]);
		return;
	}

	// skip
	makeGualho(i + 2, str, makeStr + str[i] + str[i + 1]);
	
	// pos () + 6
	if (i + 4 < maxSize) 
		makeGualho(i + 4, str, makeStr +"("+ str[i] + str[i + 1] + str[i + 2] +")"+ str[i + 3]);
	
	// pos () + end point
	if (i + 2 == maxSize-1)
		makeGualho(i + 3, str, makeStr + "("+str[i] + str[i + 1]+ str[i + 2]+")");
}

// make 후순위연산자
string makePostOrder(string input) {

	stack<char> op;
	string output = "";

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= '0' && input[i] <= '9')
			output += input[i];

		if (input[i] == '(') 
			op.push(input[i]);

		if (input[i] == ')') {
			while (1) {
				if (op.empty())
					break;

				char data = op.top();
				op.pop();

				if (data == '(')
					break;
				output += data;
			}
		}
		
		if (input[i] == '+' || input[i]=='-' || input[i]=='*') {
			while (1) {
				if (op.empty())
					break;
				char data = op.top();
				op.pop();

				if (data == '(')
					break;
				output += data;
			}
			op.push(input[i]);
		}
	}

	while (!op.empty()) {
		char data = op.top();
		op.pop();
		output += data;
	}
	return output;
}

// 후순위연산자 계산
int calc(string data) {

	stack<int> s;

	for (int i = 0; i < data.size(); i++) {
		if (data[i] >= '0' && data[i] <= '9')
			s.push(data[i] - '0');

		if (data[i] == '-') {
			int n1 = s.top();
			s.pop();
			int n2 = s.top();
			s.pop();
			s.push(n2 - n1);
		}

		if (data[i] == '+') {
			int n1 = s.top();
			s.pop();
			int n2 = s.top();
			s.pop();
			s.push(n2+n1);
		}

		if (data[i] == '*') {
			int n1 = s.top();
			s.pop();
			int n2 = s.top();
			s.pop();
			s.push(n2*n1);
		}
	}

	int output = s.top();
	return output;
	
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string str;
	cin >> str;
	maxSize = str.size();

	makeGualho(0, str, "");

	int maxResult = -1;

	for (int i = 0; i < input.size(); i++) {
		string data = input[i];
		string changeData = makePostOrder(data);
		if (i == 0)
			maxResult = calc(changeData);
		else
			maxResult = max(maxResult, calc(changeData));

	}

	cout << maxResult << "\n";
	return 0;
}