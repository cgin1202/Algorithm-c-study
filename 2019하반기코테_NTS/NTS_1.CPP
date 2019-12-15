#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int budget) {
	int answer = 0;

	int max_value = 0;
	int index_value = 0;
	if (a > b)
		index_value = b;
	else
		index_value = a;
	max_value = a > b ? a : b;
	int max_length = budget / max_value;

	for (int i = 0; i <= max_length; i++) {
		if (budget % index_value == 0)
			answer++;

		budget = budget - max_value;
	}

	return answer;
}

int main() {

	int get_Result = solution(3000, 5000, 23000);
	cout << get_Result << "\n";
	return 0;
}