#include <string>
#include <iostream>

using namespace std;

bool number_check[10];

int solution(long long n)
{

	int answer = 0;

	string input = to_string(n);
	int input_length = input.size();
	
	for (int i = 0; i < input_length; i++)
		number_check[input[i] - '0'] = true;


	for (int i = 1; i <= 9; i++) {
		if (number_check[i] == false)
			continue;
		int index_value = i;
		if (index_value == 0)
			continue;
		if (n % index_value == 0)
			answer++;
	}
	

	return answer;
}