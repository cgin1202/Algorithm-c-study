#include <string>
#include <stack>
#include <iostream>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int size = dartResult.size();

	stack<int> s;

	for (int i = 0; i < size; i++) {
		char data = dartResult[i];
		if (data >= '0' && data <= '9') {
			int realData = 0;
			if (i + 1 < size && data == '1' && dartResult[i + 1] == '0') {
				string tempData = dartResult.substr(i, 2);
				realData = stoi(tempData);
				i++;
			}
			else
				realData = data - '0';
			s.push(realData);
		}
		else if (data == 'S' || data == 'D' || data == 'T') {
			int tempData = s.top();
			s.pop();
			if (data == 'D')
				s.push(tempData * tempData);
			else if (data == 'T')
				s.push(tempData * tempData * tempData);
			else
				s.push(tempData);
		}
		else if (data == '*' || data == '#') {
			int tempData = s.top();
			s.pop();
			if (data == '#')
				s.push(-tempData);
			else {
				if (!s.empty()) {
					int tempData2 = s.top();
					s.pop();
					s.push(tempData2 * 2);
				}
				s.push(tempData * 2);
			}
		}
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}
	return answer;
}