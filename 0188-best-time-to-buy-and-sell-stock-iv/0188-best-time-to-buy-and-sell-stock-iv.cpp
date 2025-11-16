class Solution {
public:

int dp[(int)100000][2][101];
int m;
int f(int idx,bool taken,int count,vector<int>&prices){
    int n=prices.size();
    if(idx==n)return 0;
    if(dp[idx][taken][count]!=-1)return dp[idx][taken][count];
    if(taken==false and count<m){
        return dp[idx][taken][count]=max(-prices[idx]+f(idx+1,true,count,prices),f(idx+1,false,count,prices));
    }
    if(taken==true and count<m){
        return dp[idx][taken][count]=max(prices[idx]+f(idx+1,false,count+1,prices),f(idx+1,true,count,prices));
    }
     return 0;
}



    int maxProfit(int k, vector<int>& prices) {
          int n=prices.size();
        memset(dp,-1,sizeof(dp));
        m=k;
        return f(0,false,0,prices);
    }
};