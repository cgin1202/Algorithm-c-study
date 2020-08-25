#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string input;
	cin >> input;
	
	for(int i=0; i<input.size(); i++){
		char presentWord=input[i];
		int diff=presentWord-'A'-3;
		if(diff<0){
			diff++;
			input[i]='Z'+diff;
		}else
			input[i]=input[i]-3;
	}
	cout << input <<"\n";
	
	return 0;
}