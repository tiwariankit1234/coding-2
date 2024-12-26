class Solution {
public:

int dp[22][2002];
int f(vector<int>& nums,int idx,int currsum,int target,int n){
    if(idx==n){
        if(currsum==target)
        return 1;
          return 0;
    }
    if(dp[idx][currsum+1000]!=-1)return dp[idx][currsum+1000];

    return dp[idx][currsum+1000]=f(nums,idx+1,currsum-nums[idx],target,n)+ f(nums,idx+1,currsum+nums[idx],target,n);
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));

        return f(nums,0,0,target,n);
    }
};