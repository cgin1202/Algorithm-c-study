#include <iostream>
#include <string>
 
using namespace std;
 
void getResult(string left, string right){
 
	string minLeft;
	string maxLeft;
	string minRight;
	string maxRight;
 
	for(int i=0; i<left.size(); i++){
		if(left[i]=='5')
			maxLeft += "6";
		else
			maxLeft += left[i];
	}
 
	for(int i=0; i<left.size(); i++){
		if(left[i]=='6')
			minLeft += "5";
		else
			minLeft += left[i];
	}
 
	for(int i=0; i<right.size(); i++){
		if(right[i]=='5')
			maxRight += "6";
		else
			maxRight += right[i];
	}
 
	for(int i=0; i<right.size(); i++){
		if(right[i]=='6')
			minRight += "5";
		else
			minRight += right[i];
	}
 
	cout << stoi(minLeft)+stoi(minRight) <<" "<<stoi(maxLeft)+stoi(maxRight) <<"\n";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	string left, right;
	cin >> left >> right;
 
	getResult(left, right);
 
	return 0;
}