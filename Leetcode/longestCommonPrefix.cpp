class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        
        if(strs.size()==1)
            return strs[0];
        
        string prefix=strs[0];
        int prefixLength=prefix.size();
        for(int i=1; i<strs.size(); i++){
            string compare=strs[i];
            int compareLength=compare.size();
            int idx=0;
            while(idx<prefixLength && idx<compareLength && prefix[idx]==compare[idx]){
                
                idx++;
            }
            
            if(idx<prefixLength){
                prefix=compare.substr(0, idx);
                prefixLength=prefix.size();
                if(prefixLength==0)
                    return "";
            }
        }
        return prefix;
    }
};