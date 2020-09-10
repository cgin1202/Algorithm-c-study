#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    int size=s.size();
    
    for(int i=1; i<=size/2; i++){
        int index=0;
        int cnt=1;
        string output= "";
        
        while(1){
            if(index+i>=size)
                break;
            string present=s.substr(index, i);
            string next=s.substr(index+i, i);
            
            if(present==next)
                cnt++;
            else{
                if(cnt==1)
                    output += present;
                else
                    output += to_string(cnt)+present;
                cnt=1;
            }
            index += i;
        }
        
        if(cnt>1){
            string present=s.substr(index, i);
            output += to_string(cnt)+present;
        }else{
            string present=s.substr(index, i);
            output += present;
        }
        int outputSize=output.size();
        answer=min(answer, outputSize);
        //cout << output <<"\n";
    }
    return answer;
}