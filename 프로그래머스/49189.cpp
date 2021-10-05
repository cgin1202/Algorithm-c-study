#include <string>
#include <vector>
#include <queue>

using namespace std;

// 시간복잡도 O(2만+5만)

vector<int> getMaxlenNode(int &n, vector<bool> &isVisted, vector<vector<int>> &node){

    queue<int> q;
    q.push(1);
    isVisted[1]=true;
    int length=0;
    
    vector<int> answer;
    
    while(!q.empty()){
        answer.clear();
        int size=q.size();
        for(int i=0; i<size; i++){
            int pNode=q.front();
            answer.push_back(pNode);
            q.pop();
            for(int j=0; j<node[pNode].size(); j++){
                int nNode=node[pNode][j];
                if(isVisted[nNode]==true)
                    continue;
                isVisted[nNode]=true;
                q.push(nNode);
            }
        }
        length++;
    }
    
    return answer;
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> node(n+1);
    
    for(int i=0; i<edge.size(); i++){
        int left=edge[i][0];
        int right=edge[i][1];
        
        node[left].push_back(right);
        node[right].push_back(left);
    }
    
    vector<bool> isVisted(n+1,false);
    
    vector<int> result = getMaxlenNode(n, isVisted, node);
    answer= result.size();
    return answer;
}