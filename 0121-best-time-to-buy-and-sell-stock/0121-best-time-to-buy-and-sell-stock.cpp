class Solution {
public:
int dp[(int)1e5][2];
int f(int idx,bool taken,vector<int>&prices){
    int n=prices.size();
 if(idx==n){
    return 0;
 }
 if(dp[idx][taken]!=-1)return dp[idx][taken];
 int ans=INT_MIN;
 if(taken==false){
     return dp[idx][taken]=max(-prices[idx]+f(idx+1,true,prices),f(idx+1,false,prices));
 }
 if(taken==true){
    return dp[idx][taken]=max(prices[idx],f(idx+1,true,prices));
 }
 return 0;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return f(0,false,prices);
    }
};