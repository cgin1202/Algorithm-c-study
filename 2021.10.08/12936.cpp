#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> dp(30);
vector<int> answer;
vector<bool> isVisited(30, false);

void getAnser(int n, long long k){

    if(n==0)
        return;
    long long compareN=dp[n-1];
    int idx=0;
    for(int i=0; i<n; i++){
        if(compareN*i >= k)
            break;
        idx++;
    }

    cout << idx << "\n";
    int count=0;
    int deleteN = -1;
    for(int i=1; i<=20; i++){
        if(isVisited[i]==true)
            continue;
        if(count==idx-1){
            deleteN = i;
            isVisited[i]=true;
            break;
        }
        count++;
    }

    answer.push_back(deleteN);
    //cout << deleteN << "\t" << k-dp[n-1]*(idx-1) << "\n";
    getAnser(n-1, k-dp[n-1]*(idx-1));
}
vector<int> solution(int n, long long k) {

    dp[1]=1;
    for(int i=2; i<=20; i++)
        dp[i]=dp[i-1]*i;

    getAnser(n, k);
    return answer;
}