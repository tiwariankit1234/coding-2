
class Solution {
public:
int dp[10005];
int f(int i,vector<int>& nums,int n){
    // cout<<i<<endl;
    
    if(i==n-1){
        return 0;
    }
    if(nums[i]==0)return 90000;
  
   if(dp[i]!=-1)return dp[i];
   
    
   
    int ans=90000;
    int steps=nums[i];
    for(int j=steps;j>=1;j--){
        if((i+j)<n){
        ans=min(ans,1+f(i+j,nums,n));
        }
    }
    return dp[i]=ans;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        // cout<<"5"<<endl;
        return f(0,nums,n);
    }
};