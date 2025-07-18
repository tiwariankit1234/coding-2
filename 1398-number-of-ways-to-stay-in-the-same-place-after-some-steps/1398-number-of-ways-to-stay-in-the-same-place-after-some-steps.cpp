class Solution {
public:
int dp[255][502];
int mod=1e9+7;
int f(int idx,int steps,int n){
    
    // cout<<idx<<" "<<steps<<endl;
    if(steps==0){
     if(idx==0)return 1;
     else
     return 0;
    }
    if(dp[idx][steps]!=-1)return dp[idx][steps];
    int left=0;
    if(idx>=1){
        left=f(idx-1,steps-1,n)%mod;
    }
    int right=0;
    if(idx<(n-1) and idx<252){
        right=f(idx+1,steps-1,n)%mod;
    }
    int stay=f(idx,steps-1,n)%mod;
    return dp[idx][steps]=(((stay+right)%mod+left)%mod)%mod;
}
    int numWays(int steps, int arrLen) {
    
        memset(dp,-1,sizeof(dp));
        // cout<<"5"<<endl;
        
        return f(0,steps,arrLen);
    }
};