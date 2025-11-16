class Solution {
public:
int dp[(int)5002][2];
int f(int idx,bool taken,vector<int>&prices){

    int n=prices.size();
    if(idx>=n)return 0;
    if(dp[idx][taken]!=-1)return dp[idx][taken];
    if(taken==false){
   
        return dp[idx][taken]=max(-prices[idx]+f(idx+1,true,prices),f(idx+1,taken,prices));
    }
    if(taken==true){
        return dp[idx][taken]=max(prices[idx]+f(idx+2,false,prices),f(idx+1,taken,prices));
    }
    return 0;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return f(0,false,prices);
    }
};