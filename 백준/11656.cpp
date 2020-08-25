#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string input;
	cin >> input;
	
	string tempInput="";
	vector<string> output;
	for(int i=input.size()-1; i>=0; i--){
		tempInput= input[i]+tempInput;
		output.push_back(tempInput);
	}
	
	sort(output.begin(), output.end());
	for(int i=0; i<output.size(); i++)
		cout << output[i] <<"\n";
	return 0;
}