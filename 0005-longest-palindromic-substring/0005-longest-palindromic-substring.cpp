class Solution {
public:
int dp[1002][1002];

    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)return s;
        int start=0,maxlen=1;
        auto expand=[&](int l,int r){
           while(l>=0 and r<n and s[l]==s[r]){
            l--;
            r++;
           }
        int length=r-l-1;
        if(length>maxlen){
            maxlen=length;
            start=l+1;
        }


        };



    
    for(int i=0;i<n;i++){
        expand(i,i);
        expand(i,i+1);
    }
        return s.substr(start,maxlen);
           }
};