#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

void getParent(vector<int> &parent, vector<int> &answer, int x, int value){
    if(x==-1)
        return;
    else{
        double data = ceil(value*0.9);
        //cout << x << "\t"<< value << "\t"<< data << "\n";
        answer[x] += data;
        getParent(parent, answer, parent[x], value-data);
    }
        
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> m;
    m["-"]=-1;
    for(int i=0; i<enroll.size(); i++){
        string name=enroll[i];
        m[name]=i;
    }   
    
    vector<int> parent(enroll.size()+1, 0);
    
    int n=enroll.size();
    answer.resize(n, 0);
    
    for(int i=0; i<n; i++)
        parent[i]=i;
    
    for(int i=0; i<referral.size(); i++){
        string name = referral[i];
        parent[i]=m[name];
    }
    
    
    for(int i=0; i<seller.size(); i++){
        string name=seller[i];
        int idx = m[name];
        getParent(parent, answer, idx, amount[i]*100);
    }
    
    return answer;
}