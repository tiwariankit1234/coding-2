class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.size();
        int j=0,i=n-1;
        while(j<n){
            if(s[j]=='0')j++;
            else{
                break;
            }
        }
        int index=-1;
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')&1){
              index=i;
              break;
            }
        }
        if(index==-1)return "";
        return s.substr(j,index-j+1);
    }
};