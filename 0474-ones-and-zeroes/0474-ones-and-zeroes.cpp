class Solution {
public:
int dp[602][102][102];
int f(int idx,vector<string>& strs,int m,int n){
       int k=strs.size();
        if(m<0||n<0)return INT_MIN;
       if(idx==k){
           
          return 0;
       }
   
       if(dp[idx][m][n]!=-1)return dp[idx][m][n];
       int zeros=0;
       int ones=0;
       string s=strs[idx];
       for(int i=0;i<s.size();i++){
        if(s[i]=='0')zeros++;
        else
        ones++;
       }
       
       return dp[idx][m][n]=max(1+f(idx+1,strs,m-zeros,n-ones),f(idx+1,strs,m,n));
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,strs,m,n);
    }
};