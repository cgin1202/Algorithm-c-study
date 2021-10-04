#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> splitStr(string str){
    vector<string> answer; 
    stringstream ss(str);
    string temp;
    
    while(getline(ss, temp, ' '))
        answer.push_back(temp);
    return answer;
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> dq;
    for(int i=0; i<operations.size(); i++){
        string op=operations[i];
        vector<string> outputStr=splitStr(op);
        if(outputStr[0]=="I"){
            dq.push_back(stoi(outputStr[1]));
            sort(dq.begin(), dq.end());
        }
        
        if(outputStr[0]=="D"){
            if(dq.size()==0)
                    continue;
            
            if(outputStr[1]=="-1"){
                dq.pop_front();
            }            
            else{
                dq.pop_back();
            }
        }
            
    }
    
    if(dq.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}