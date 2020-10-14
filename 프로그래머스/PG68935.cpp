#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> input;
    while(n>0){
        int temp=n%3;
        n=n/3;
        input.push_back(temp);
    }
    int size=input.size();
    
    int cnt=1;
    for(int i=size-1; i>=0; i--){
        answer = answer + (cnt*input[i]);
        cnt=cnt*3;
    }
    return answer;
}