#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isCheckEqual(string input){
	stack<string> s;
	
	for(int i=0; i<input.size(); i++){
		if(input[i]=='(')
			s.push("(");
		else if(input[i]=='[')
			s.push("[");
		else if(input[i]==']'){
			if(s.size()==0)
				return false;
			else if(s.top()=="[")
				s.pop();
			else
				return false;
		}
		else if(input[i]==')'){
			if(s.size()==0)
				return false;
			else if(s.top()=="(")
				s.pop();
			else
				return false;
		}
	}
	if(s.size()>0)
		return false;
	return true;
}
int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	while(1){
		string input;
		getline(cin, input);
		
		if(input==".")
			break;
		if(isCheckEqual(input)==true)
			cout <<"yes\n";
		else
			cout << "no\n";
	}
	
	return 0;
}