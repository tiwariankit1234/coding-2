class Solution {
public:
int dp[40002][3];
int f(int idx,int mod,vector<int>&nums){
    int n=nums.size();
    if(idx==n){
        if(mod==0)return 0;
        else{
            return -1e5;
        }
    }

    if(dp[idx][mod]!=-1)return dp[idx][mod];
    int take=nums[idx]+f(idx+1,(mod+nums[idx])%3,nums);
    int notake=f(idx+1,(mod),nums);
    return dp[idx][mod]=max(take,notake);
}

    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
      int ans=f(0,0,nums);
      if(ans<0)return 0;
      return ans;
    }
};