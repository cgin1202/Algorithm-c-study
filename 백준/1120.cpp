#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string left, right;
	cin >> left >> right;
	
	int gap=right.size()-left.size();
	int minDiff=1e9;
	
	for(int i=0; i<gap+1; i++){
		int countDiff=0;
		for(int j=0; j<left.size(); j++)
			if(left[j]!=right[i+j])
				countDiff++;
		minDiff=min(minDiff, countDiff);
	}
	
	cout << minDiff <<"\n";
	return 0;
}