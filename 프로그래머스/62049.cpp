#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	answer.push_back(0);
	if (n == 1)
		return answer;
	for (int i = 2; i <= n; i++) {
		vector<int> temp = answer;
		answer.push_back(0);
		for (int j = temp.size() - 1; j >= 0; j--) {
			if (temp[j] == 0)
				answer.push_back(1);
			else
				answer.push_back(0);
		}
	}
	return answer;
}