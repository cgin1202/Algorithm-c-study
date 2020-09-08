#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getStr(int n, int input){
    string output="";
    
    while(input>0){
        int temp=input%2;
        input=input/2;
        output = to_string(temp)+output;
    }
    
    while(output.size()<n)
        output = "0"+output;
    
    return output;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<vector<char>> board1;
    vector<vector<char>> board2;
    
    board1.resize(n, vector<char> (n, ' '));
    board2.resize(n, vector<char> (n, ' '));
    
    for(int i=0; i<arr1.size(); i++){
        int data=arr1[i];
        string output=getStr(n, data);
        for(int j=0; j<n; j++)
            board1[i][j]=output[j];
    }
    for(int i=0; i<arr2.size(); i++){
        int data=arr2[i];
        string output=getStr(n, data);
        for(int j=0; j<n; j++)
            board2[i][j]=output[j];
    }
    for(int i=0; i<n; i++){
        string tempOutput="";
        for(int j=0; j<n; j++){
            if(board1[i][j]==board2[i][j] && board1[i][j]=='0')
                tempOutput += " ";
            else
                tempOutput += "#";
        }
        //cout << tempOutput <<"\t";
        answer.push_back(tempOutput);
    }
    return answer;
}