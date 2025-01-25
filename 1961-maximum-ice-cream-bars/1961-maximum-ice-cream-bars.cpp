class Solution {
public:

int f(int idx,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(idx==coins.size())return 0;
        if(dp[idx][amount]!=-1)return dp[idx][amount];
       int take=INT_MIN;
    if(amount-coins[idx]>=0){
        take=1+f(idx+1,coins,amount-coins[idx],dp);
    }
    int notake=f(idx+1,coins,amount,dp);
    return dp[idx][amount]=max(take,notake);
}
    int maxIceCream(vector<int>& costs, int coins) {
        // vector<vector<int>>dp(costs.size()+1,vector<int>(coins+1,-1
        // ));
        // return f(0,costs,coins,dp)
         sort(costs.begin(),costs.end());
         int n=costs.size();
         int ans=0,j=0;
         while(j<n and coins-costs[j]>=0 ){
            ans++;
            
            coins-=costs[j];
            j++;
         }
         return ans;
    }
};