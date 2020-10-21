class Solution {
public:
    bool isPalindrome(int x) {
        string str=to_string(x);
        int length=str.size();
        
        int start=0;
        int end=length-1;
        for(int i=0; i<length/2; i++){
            if(str[start]!=str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};