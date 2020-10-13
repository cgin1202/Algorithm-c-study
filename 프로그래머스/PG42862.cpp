#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> result(n+1, 1);
    
    for(int i=0; i<lost.size(); i++)
        result[lost[i]]--;
    
    for(int i=0; i<reserve.size(); i++)
        result[reserve[i]]++;
    
    
    for(int i=1; i<=n; i++){
        if(result[i]==0){
            if(i!=1 && result[i-1]==2){
                result[i-1]--;
                result[i]++;
                continue;
            }
        
            if(i!=n && result[i+1]==2){
                result[i+1]--;
                result[i]++;
                continue;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
        if(result[i]>=1)
            answer++;
    return answer;
}