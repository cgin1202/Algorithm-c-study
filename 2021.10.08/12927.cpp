#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<long long> pq;
    for(int i=0; i<works.size(); i++)
        pq.push(works[i]);
    
    for(int i=0; i<n; i++){
        if(pq.size()==0)
            return 0;
        int val = pq.top();
        pq.pop();
        if(val-1!=0)
            pq.push(val-1);
    }
    
    while(!pq.empty()){
        long long data = (long long)pq.top();
        pq.pop();
        answer = answer + data*data;  
    }
    return answer;
}