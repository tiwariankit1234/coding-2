class Solution {
public:
int mod=1e9+7;
int dp[100005];
int f(int length,int idx,int numzero,int numone){
    if(length==0){
        return 1;
    }
    if(dp[length]!=-1)return dp[length];
    int count=0;
    if((length-numzero)>=0){
       count+=f(length-numzero,idx+1,numzero,numone)%mod;
    }
    if((length-numone)>=0){
        count+=f(length-numone,idx+1,numzero,numone)%mod;
    }
    return dp[length]=count;
}
    int countGoodStrings(int low, int high, int numzero, int numone) {
            memset(dp,-1,sizeof(dp));
           int ans=0;
         for(int i=low;i<=high;i++){
            ans+=f(i,0,numzero,numone)%mod;
            ans=ans%mod;
        }
        return ans;
    }

};