class Solution {
public:
// f(int idx,vector<int>&amount,int n) will calculate the least number of perfect square numbers from idx to n;
int dp[1002][10005];
 int f(int idx,vector<int>&amount,int n){
   if(n<0)return 100000;
    if(idx==(amount.size())){
        if(n>0){
            return 100000;
        }
        if(n==0)
        return 0;
        if(n<0)
        return 100000;
    }
         if(dp[idx][n]!=-1)return dp[idx][n];
        // cout<<idx<<" "<<" "<<(n-amount[idx])<<endl;
    int pick=1+f(idx,amount,n-amount[idx]);
    int nonpick=f(idx+1,amount,n);
    
     return dp[idx][n]=min(pick,nonpick);
 }

    int numSquares(int n) {
        vector<int>amount;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=sqrt(n);i++){
           amount.push_back(i*i);
        }
        // for(auto it:amount)
        // cout<<it<<" ";
        // cout<<endl;
        return f(0,amount,n);
    }
};