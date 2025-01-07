class Solution {
public:
int m;
int mod=1e9+7;
int dp[31][1002];
 int f(int n,int k,int target){
    if(target<0)return 0;
    if(n==0){
        if(target==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    int ans=0;
    cout<<n<<" "<<k<<" "<<target<<endl;
    for(int i=1;i<=k;i++){
      ans=(ans+f(n-1,k,target-i))%mod;

      ans%=mod;
    }
    return dp[n][target]=ans%mod;
 }
    int numRollsToTarget(int n, int k, int target) {
       memset(dp,-1,sizeof(dp));
        return f(n,k,target);
    }
};