#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> v;
void dfs(int idx, int m, string output){
    for(int i=idx; i<m; i++){
        string temp=to_string(i);
        output += temp;
        v.push_back(output);
        dfs(i+1, m, output);
        output.pop_back();
    }
}

bool compare(string x, string y){
    if(x.size()<y.size())
        return true;
    else if(x.size()==y.size())
        return x<y;
    else
        return false;
}

bool isNotCan=false;
void dfsSubset(int idx, int n, int length, string left, string right, string compareStr){
    if(n==length){
        if(left==right)
            isNotCan=true;
        return;
    }
    
    for(int i=idx; i<compareStr.size(); i++){
        right += compareStr[i];
        dfsSubset(i, n+1, length, left, right, compareStr);
        right.pop_back();
    }
}
bool isCheckResult(vector<string> &result, string compareStr){
    for(int i=0; i<result.size(); i++){
        string left=result[i];
        isNotCan=false;
        
        dfsSubset(0, 0, left.size(), left, "", compareStr);
        if(isNotCan==true)
            return true;
    }
    //cout << compareStr <<"true"<<"\n";
    return false;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int n=relation.size();
    int m=relation[0].size();
    
    dfs(0, m, "");
    
    sort(v.begin(), v.end(), compare);
    
    vector<bool> isVisited(m+1,false);
    vector<string> result;
    
    for(int i=0; i<v.size(); i++){
        string temp=v[i];
        
        // 후보키 선별
        if(isCheckResult(result, temp)==true)
            continue;
        
        map<string, int> m;
        for(int k=0; k<n; k++){
            string temp2="";
            for(int j=0; j<temp.size(); j++){
                int index=temp[j]-'0';
                temp2 += (relation[k][index]+" ");   
            }
            m[temp2]++;
        }
        map<string, int>::iterator it;
        bool isError=false;
        for(it=m.begin(); it!=m.end(); it++)
            if(it->second>1)
                isError=true;
        if(isError==false){
            
            // 후보키 등록
            result.push_back(temp);
        }
    }
    answer=result.size();
    return answer;
}