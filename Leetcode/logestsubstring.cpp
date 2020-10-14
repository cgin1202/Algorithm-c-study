#include <map>
#include <algorithm>

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int size=s.size();
        if(size==0)
            return 0;
        
        int answer=1;
        
        int leftindex=0;
        map<char, int> m;
        m[s[0]]++;
        int rightindex=1;
        while(1){
            if(leftindex>=size || rightindex>=size)
                break;
            
            char rightdata=s[rightindex];
            char leftdata=s[leftindex];
            
            if(m[rightdata]==0){
                m[rightdata]++;
                rightindex++;
                answer=max(answer, rightindex-leftindex);
            }else{
                m[leftdata]=0;
                leftindex++;
            }
            
            //cout << leftindex <<"\t"<<rightindex <<"\n";
        }
        
        return answer;
    }
};