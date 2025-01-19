class Solution {
public:
int dp[1002][102][3];
int f(int idx,int k,vector<int>& prices,bool flag){
    int n=prices.size();
    if(idx==n)return 0;
    if(idx==n-1){
        if(flag){
            return prices[idx];
        }
        else{
            return 0;
        }
    }
    if(dp[idx][k][flag]!=-1)return dp[idx][k][flag];
    int profit=0;
    if(!flag and k>0){
        profit=max(-prices[idx]+f(idx+1,k,prices,true),f(idx+1,k,prices,false));
    }
    if(flag and k>0){
        profit=max(prices[idx]+f(idx+1,k-1,prices,false),f(idx+1,k,prices,flag));
    }
    return dp[idx][k][flag]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,k,prices,false);
    }
};