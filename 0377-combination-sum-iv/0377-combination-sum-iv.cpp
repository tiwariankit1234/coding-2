class Solution {
public:
int dp[10002];
int f(int target,int n,vector<int>& nums){
   if(target<0)return 0;
   if(target==0)return 1;
  int ans=0;
  if(dp[target]!=-1)return dp[target];
  for(int i=0;i<n;i++){
    ans+=f(target-nums[i],n,nums);
  }
  return dp[target]=ans;

}
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return f(target,n,nums);
    }
};