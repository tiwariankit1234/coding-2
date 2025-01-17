class Solution {
public:
int dp[1001];

bool helper(int n){
if(n==1)return false;
     
        bool ans=false;
         if(dp[n]!=-1)return dp[n];
        for(int i=1;i<=(n/2);i++){
            if(n%i==0){
                ans=helper(n-i);
                if(ans==false)return dp[n]= true;
            }
        }
        return dp[n]=false;
}

    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
        
    }
};