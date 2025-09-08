class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        if(s.size()==1)return n;
        if(s.size()==2){
            if(s[0]<=s[1]){
              return n;
            }
            else
            {
               int x=((s[0]-'0')-1)*10+9;
                  return x;
            }
        }
        int index=-1,k=s.size();
        for(int i=0;i<(k-1);i++){
            if(s[i]>s[i+1]){
                index=i;
                break;
            }
        }
           if(index==-1)return n;

            int idx=-1;
        for(int i=0;i<(k-1);i++){
            if(s[i]>s[i+1]){
                idx=i;
                break;
            }
        }
        int l=idx;
        int ch=s[idx];
        while(idx>=0 and s[idx]==ch){
            idx--;
        }
        idx++;
        s[idx]=s[idx]-1;
        idx++;
        
      
        for(int j=idx;j<k;j++){
            s[j]='9';
        }
       
             return stoi(s);
    }
};