#include <map>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;
        int size=nums.size();
        for(int i=0; i<size; i++)
            m[nums[i]]++;
        
        nums.clear();
        
        int output=m.size();
        //vector<int> v;
        map<int, int>::iterator it;
        for(it=m.begin(); it!=m.end(); it++)
            nums.push_back(it->first);
        
        return nums.size();
    }
};