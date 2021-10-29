#include <iostream>
#include <deque>
using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	deque<int> dq;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		dq.push_back(i + 1);

	int answer = 0;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		if (dq.at(0) == num)
			dq.pop_front();
		else {
			int size = dq.size();
			int findIdx = -1;
			for (int j = 0; j < size; j++) {
				if (dq.at(j) == num) {
					findIdx = j;
					break;
				}
			}

			int leftCnt = findIdx;
			int rightCnt = size - leftCnt;

			if (leftCnt < rightCnt) {
				for (int j = 0; j < leftCnt; j++) {
					int tempData = dq.at(0);
					dq.pop_front();
					dq.push_back(tempData);
				}
				answer += leftCnt;
			}
			else {
				for (int j = 0; j < rightCnt; j++) {
					int tempData = dq.at(size-1);
					dq.pop_back();
					dq.push_front(tempData);
				}
				answer += rightCnt;
			}


			dq.pop_front();
		}
	}

	cout << answer << "\n";

	return 0;
}