class Solution {
public:
string s="";
int dp[202][202][202];
int f(int i,int j,int k){
    if(i>j)return 0;
    if(i==j)return 1;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int res=INT_MIN;
    if(s[i]==s[j]){
        int ans=2+f(i+1,j-1,k);
        res=max(res,ans);
    }
    else{
        // shift i
        int a=f(i+1,j,k);
        res=max(a,res);
        // shift j
        int b=f(i,j-1,k);
        res=max(res,b);
        int cost=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        if(k>=cost){
            int newk=k-cost;
        res=max(res,2+f(i+1,j-1,newk));
        }
    }
    return dp[i][j][k]=res;
}
    int longestPalindromicSubsequence(string t, int k) {
        s=t;
        int n=t.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,k);
    }
};