#include <algorithm>

bool compare(pair<int, int> x, pair<int, int> y){
        if(x.second<y.second)
            return true;
        else if(x.second==y.second)
            return x.first>y.first;
        else
            return false;
}

class Solution {
public:
    
    int findValue(int size, vector<pair<int, int>> &v, int target){
        int begin=0;
        int end=size-1;
        
        while(begin<=end){
            int middle=(begin+end)/2;
            if(v[middle].second==target)
                return middle;
            else if(v[middle].second>target)
                end=middle-1;
            else
                begin=middle+1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> answer;
        
        vector<pair<int, int>> v;
        for(int i=0; i<nums.size(); i++)
            v.push_back({i, nums[i]});
        
        sort(v.begin(), v.end(), compare);
        
        int size=nums.size();
        for(int i=0; i<size; i++){
            int presentKey=v[i].second;
            int findKey=target-presentKey;
            
            int findIndex=findValue(size, v, findKey);
            //cout << i << "\t"<<findIndex<<"\n";
            
            
            if(findIndex==-1)
                continue;
            
            if(i+1<size && v[i].second==v[i+1].second && v[i].second+v[i+1].second==target){
                answer.push_back(v[i].first);
                answer.push_back(v[i+1].first);
                break;
            }
            answer.push_back(v[i].first);
            answer.push_back(v[findIndex].first);
            break;
        }
        
        return answer;
    }
};