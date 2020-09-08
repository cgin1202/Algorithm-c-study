#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>

using namespace std;

string transformStr(string input){
    for(int i=0; i<input.size(); i++)
        if(input[i]>='a' && input[i]<='z')
            input[i]=input[i]-32;
    return input;
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	if (cacheSize == 0)
		return 5 * cities.size();

	map<string, int> cityCheck;
	int qSize = 0;
	deque<string> dq;

	for (int i = 0; i < cities.size(); i++) {
		string cityName = transformStr(cities[i]);
		if(cityCheck.find(cityName) != cityCheck.end() && cityCheck[cityName]!=0){	// 데이터가 있음
			deque<string>::iterator it;
			for (it = dq.begin(); it != dq.end(); it++)
				if (*it == cityName) {
					dq.erase(it);
					break;
				}
			dq.push_back(cityName);
			answer++;
		}
		else {
			qSize++;
			dq.push_back(cityName);
			cityCheck[cityName] = 1;
			answer += 5;
		}

		if (qSize > cacheSize) {
			string tempStr=dq.front();
			dq.pop_front();
			cityCheck[tempStr] = 0;
			qSize--;
		}

        /*
		deque<string>::iterator it;
		for (it = dq.begin(); it != dq.end(); it++)
			cout << *it << "\t";
		cout << "\n";
        */
	}
	return answer;
}