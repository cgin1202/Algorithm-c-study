class Solution {
public:
    int reverse(int x) {
        
        if(x==0)
            return 0;
        
        
        
        vector<int> input;
        bool isMinus=false;
        
        long long checkResult2=x;
        if(-checkResult2>2147483647)
            return 0;
        
        if(x<0){
            isMinus=true;
            x=-x;
        }
        
        while(x>0){
            int data=x%10;
            x=x/10;
            input.push_back(data);
        }
        
        int size=input.size();
        string output ="";
        for(int i=0; i<size; i++){
            
            // zero skip
            if(i==0){
                while(i<size && input[i]==0)
                    i++;
            }
            output += to_string(input[i]);
        }
        
        if(isMinus==true)
            output = "-"+output;
        long long checkResult=stoll(output);
        if(checkResult>2147483647 || checkResult<-2147483648)
            return 0;
        
        int getResult=stoi(output);
        return getResult;
    }
};