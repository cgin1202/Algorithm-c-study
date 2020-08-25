#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	map<string, int> nameCnt;
	int cnt=0;
	
	for(int i=0; i<n+m; i++){
		string input;
		cin >> input;
		nameCnt[input]++;
		if(nameCnt[input]==2)
			cnt++;
	}
	
	map<string, int>::iterator it;
	cout << cnt <<"\n";
	for(it=nameCnt.begin(); it!=nameCnt.end(); it++)
		if(it->second==2)
			cout << it->first <<"\n";
	return 0;
}