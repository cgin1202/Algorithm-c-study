class Solution {
public:
    int myAtoi(string s) {
        
        int size=s.size();
        bool isStartCheck=false;
        
        for(int i=0; i<size; i++){
            if(s[i]==' ')
                continue;
            
            if(isStartCheck==false && (s[i]>='a' && s[i]<='z'))
                return 0;
            else if(isStartCheck==false && (s[i]>='A' && s[i]<='Z'))
                return 0;
            else if(isStartCheck==false && (s[i]=='.'))
                return 0;
            else{
                int output=0;
                long long tempCheck=0;
                
                bool isMinus=false;
                 string getStr="";
                if(s[i]=='-'){
                    isMinus=true;
                    i++;
                }
                else if(s[i]=='+')
                    i++;
                
                while(i<size && s[i]=='0'){
                    if(s[i]!='0')
                        break;
                    i++;
                }

                while(1){
                    if(i<size && s[i]>='0' && s[i]<='9'){
                        getStr.push_back(s[i]);
                        i++;
                    }else
                        break;
                }
                if(getStr.size()==0)
                    return 0;
                
                if(isMinus==true)
                    getStr="-"+getStr;
                
                if(getStr.size()>11){
                    if(isMinus==true)
                        return -2147483648;
                    else
                        return 2147483647;
                }
                
                tempCheck=stoll(getStr);
                if(tempCheck<=-2147483648)
                    output=-2147483648;
                else if(tempCheck>=2147483647)
                    output=2147483647;
                else
                    output=tempCheck;
                return output;
            }
        }
        return 0;
    }
};