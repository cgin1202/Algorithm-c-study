#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string transformStr(string input){
    for(int i=0; i<input.size(); i++){
        if(input[i]>='a' && input[i]<='z')
            input[i]=input[i]-32;
    }
    return input;
}

void makeStrCombination(string str, map<string, int> &m){
    for(int i=0; i<str.size()-1; i++){
        char data1=str[i];
        char data2=str[i+1];
        if(data1>='A' && data1<='Z' && data2>='A' && data2<='Z'){
            string tempStr=str.substr(i, 2);
            //cout << tempStr <<"\t";
            m[tempStr]++;
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    
    str1=transformStr(str1);
    str2=transformStr(str2);
   // cout << str1 <<"\t"<<str2 <<"\n";
    map<string, int> m1;
    map<string, int> m2;
    makeStrCombination(str1, m1);
    //cout <<"\n";
    makeStrCombination(str2, m2);
    
    
    map<string, int>::iterator it;
    map<string, int>::iterator it2;
    
    int aSize=0;
    int bSize=0;
    
    for(it=m1.begin(); it!=m1.end(); it++)
        aSize += it->second;

    
    for(it2=m2.begin(); it2!=m2.end(); it2++)
        bSize += it2->second;
    
    int commonSize=0;
    for(it=m1.begin(); it!=m1.end(); it++){
        for(it2=m2.begin(); it2!=m2.end(); it2++){
            if(it->first==it2->first){
                commonSize += min(it->second, it2->second);
            }
        }
    }
    int allSize=aSize+bSize-commonSize;
    //cout << aSize <<"\t"<<bSize <<"\t"<<commonSize<<"\t"<<allSize<<"\n";
    
    if(aSize==bSize && aSize==0)
        answer=65536;
    else
        answer=65536*(double(commonSize)/double(allSize));
    return answer;
}