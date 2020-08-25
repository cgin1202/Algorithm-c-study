#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string x, string y){
	if(x>=y)
		return true;
	else
		return false;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	map<string, int> presentPeopleCheck;
	
	
	for(int i=0; i<n; i++){
		string name, op;
		cin >> name >> op;
		if(op=="enter")
			presentPeopleCheck[name]=1;
		else
			presentPeopleCheck[name]=2;
	}
	
	map<string, int>::iterator it;
	vector<string> output;
	for(it=presentPeopleCheck.begin(); it!=presentPeopleCheck.end(); it++)
		if(it->second==1)
			output.push_back(it->first);
	
	sort(output.begin(), output.end(), compare);
	
	for(int i=0; i<output.size(); i++)
		cout << output[i] <<"\n";
	return 0;
}