#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        int size=s.size();
        for(int i=0; i<size; i++){
            char data=s[i];
            if(data=='(' || data=='[' || data=='{')
                st.push(data);
            else{
                if(st.empty())
                    return false;
                char topdata=st.top();
                
                if((topdata=='{' && data=='}') || (topdata=='(' && data==')') || (topdata=='[' && data==']'))
                    st.pop();
                else
                    return false;
            }
        }
        if(st.size()>0)
            return false;
        return true;
    }
};