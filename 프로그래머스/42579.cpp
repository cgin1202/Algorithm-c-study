#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare2(pair<int, int> x, pair<int, int> y){
    if(x.first > y.first)
        return true;
    else if(x.first<y.first)
        return false;
    else
        return x.second < y.second;
}

bool compare(pair<string, int> x, pair<string, int> y){
    if(x.second > y.second)
        return true;
    else
        return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> m;
    int pid = 0;
    vector<pair<string, int>> sum(101);
    vector<vector<pair<int, int>>> board(101);
    
    int size=genres.size();
    for(int i=0; i<size; i++){
        string key = genres[i];
        int val = plays[i];
        if(m.find(key)==m.end()){
            m[key]=pid;
            pid++;
        }
        
        int idx=m[key];
        board[idx].push_back({val, i});
        sum[idx].second += val;
        sum[idx].first=key;
    }
    
    int fullSize=pid;

    sort(sum.begin(), sum.begin()+fullSize, compare);
    
    for(int i=0; i<fullSize; i++){
        string genre=sum[i].first;
        int keyIdx=m[genre];
        int size=board[keyIdx].size();
        sort(board[keyIdx].begin(), board[keyIdx].end(), compare2);
        
        if(size==1)
            answer.push_back(board[keyIdx][0].second);
        else{
            for(int j=0; j<size; j=j+2){
                if(j+2>size)
                    break;
                answer.push_back(board[keyIdx][j].second);
                answer.push_back(board[keyIdx][j+1].second);   
            }
        }
    }
    return answer;
}