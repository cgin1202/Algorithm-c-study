#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
void dijkstr(int start, vector<vector<pair<int, long long>>> &graph, vector<long long> &dist){

    dist[start]=0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, start});

    while(!pq.empty()){

        long long dis=-pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(dist[node]<dis)
            continue;
        
        for(int i=0; i<graph[node].size(); i++){
            int nextNode=graph[node][i].first;
            long long cost = graph[node][i].second;
            long long nextCost = max(cost, dis);

            if(nextCost < dist[nextNode]){
                dist[nextNode]=nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}

bool isPrime(long long value){
    if(value==1)
        return false;

    if(value==2)
        return true;

    for(long long i=2; i<=value/2; i++){
        if(value%i==0)
            return false;
    }

    return true;
}
int main(int argc, char** argv){

    cin >> n >> m;

    long long inf = (long long)100001*(long long)1000000001;

    vector<vector<pair<int, long long>>> graph(n+1);
    vector<long long> dist(n+1, inf);
    for(int i=0; i<m; i++){
        int x,y;
        long long length;
        cin >> x >> y >> length;
        graph[x].push_back({y, length});
        graph[y].push_back({x, length});
    }

    dijkstr(1, graph, dist);


    long long maxValue=-1;

    for(int i=1; i<=n; i++)
        maxValue = max(maxValue, dist[i]);

    while(1){
        if(isPrime(maxValue)==true)
            break;

        maxValue++;
    }
    
    cout << maxValue << "\n";
    return 0;
}