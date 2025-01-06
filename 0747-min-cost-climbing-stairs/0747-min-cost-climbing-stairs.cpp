class Solution {
public:
int dp[1000];
int f(int idx,int n,vector<int>& cost){
    if(idx>n)return 9000;
    if(idx==n){
        return 0;
    }
    if(dp[idx]!=-1)return dp[idx];
    return dp[idx]=min(cost[idx]+f(idx+2,n,cost),cost[idx]+f(idx+1,n,cost));
}
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return min(f(0,n,cost),f(1,n,cost));
    }
};