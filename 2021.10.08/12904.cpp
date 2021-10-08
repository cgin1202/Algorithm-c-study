#include <iostream>
#include <string>
using namespace std;

int longest =0;
string sstring;
int ssize=0;

// even max length
void getEvenLength(int idx){
    
    int length=0;
    
    for(int i=0; i<ssize; i++){
    
        if(idx-i<0 || idx+i+1>=ssize)
            break;
        if(sstring[idx-i]==sstring[idx+i+1])
            length += 2;
        else
            break;
    }
    
    if(length>longest)
        longest = length;
}

// odd max length
void getOddLength(int idx){
    
    int length = 1;
    for(int i=1; i<ssize; i++){
        
        if(idx-i<0 || idx+i >= ssize)
            break;
        
        if(sstring[idx-i]==sstring[idx+i])
            length+= 2;
        else
            break;
    }
    
    if(length > longest)
        longest = length;
}

int solution(string s)
{
    sstring = s;
    ssize = s.size();
    
    
    for(int i=0; i<s.size(); i++){
        getEvenLength(i);
        getOddLength(i);
    }
    int answer=longest;
    return answer;
}
