class Solution {
public:
int dp[202][202];
int f(int i,int j){
    
    if(i>=j)
    return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=50000;
    for(int k=i;k<=j;k++){
        ans=min(ans,k+max(f(i,(k-1)),f(k+1,j)));
    }
    return dp[i][j]=ans;
}
    int getMoneyAmount(int n) {
        if(n==1)return 0;
        memset(dp,-1,sizeof(dp));
        return f(1,n);
    }
};