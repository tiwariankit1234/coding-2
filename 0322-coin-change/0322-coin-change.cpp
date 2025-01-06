class Solution {
public:
int dp[14][100005];
int f(int idx,vector<int>& coins,int amount){
    int n=coins.size();
    if(amount<0){
        return 100000;
    }
    if(idx==n){
        if(amount==0)
        return 0;
        if(amount>0)
        return 100000;
    }
    if(dp[idx][amount]!=-1)return dp[idx][amount];

    return dp[idx][amount]=min(1+f(idx,coins,amount-coins[idx]),f(idx+1,coins,amount));
}
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        // for(auto it:dp)
        // // cout<<it<<" ";
        cout<<endl;
        return (f(0,coins,amount))==100000?-1:f(0,coins,amount);
    }
};