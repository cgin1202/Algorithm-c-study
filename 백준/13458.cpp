#include <iostream>
#include <vector>

using namespace std;

vector<long long> board(1000001);
int n;
long long b, c;


long long playGame() {
	long long getResult = 0;

	
	for (int i = 1; i <= n; i++) {
		long long tempResult = 0;

		int studentNum = board[i];
		if (studentNum <= b)
			tempResult = 1;
		else {
			studentNum = studentNum - b;
			tempResult++;
			long long tempData = 0;
			if(studentNum%c==0)
				tempData= studentNum / c;
			else
				tempData = studentNum / c+1;
			tempResult += tempData;

		}

		getResult += tempResult;
	}
	return getResult;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	cin >> b >> c;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	init();

	cout << playGame() << "\n";
	return 0;
}