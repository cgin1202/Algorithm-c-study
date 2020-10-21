class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        
        int maxLength=s.size();
        vector<vector<char>> arr(maxLength+1);
        for(int i=1; i<=maxLength; i++)
            arr[i].resize(maxLength+1);
        
        for(int i=1; i<=maxLength; i++){
            for(int j=1; j<=maxLength; j++)
                arr[i][j]='0';
        }
        
        int idx=0;
        // false : 내려가기
        // true : 대각선 상승
        bool flag=false;
        int x=1;
        int y=1;
        int presentLength=1;
        
        while(1){
            if(idx==maxLength)
                break;
            
            if(presentLength==numRows){
                presentLength=1;
                if(flag==false)
                    flag=true;
                else
                    flag=false;
            }
            
            
            if(flag==false){
                arr[y][x]=s[idx];
                y++;
            }else{
                arr[y][x]=s[idx];
                y--;
                x++;
            }
            presentLength++;
            idx++;
        }
        
        string output = "";
        for(int i=1; i<=maxLength; i++){
            for(int j=1; j<=maxLength; j++)
                if(arr[i][j]!='0'){
                    output.push_back(arr[i][j]);
                }
        }
        return output;
    }
};