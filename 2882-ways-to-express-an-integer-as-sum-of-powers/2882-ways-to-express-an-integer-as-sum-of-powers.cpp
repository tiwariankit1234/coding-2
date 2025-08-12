class Solution {
public:
int mod=1e9+7;
int dp[302][302];
int f(int i,int n,int x){
    if(n==0)return 1;
   if(i>n)return 0;
    if(dp[i][n]!=-1)return dp[i][n];
    // take condition
    int take=f(i+1,n-(pow(i,x)),x)%mod;
    int notake=f(i+1,n,x)%mod;
    return dp[i][n]=(take%mod+notake%mod)%mod;
}
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return f(1,n,x);

    }
};