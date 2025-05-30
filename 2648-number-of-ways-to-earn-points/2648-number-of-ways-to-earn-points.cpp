class Solution {
public:
int dp[51][10002];
int mod=1e9+7;
int f(int idx,int target,vector<vector<int>>&nums){
    int n=nums.size();
    if(idx==n){
        if(target==0)return 1;
        else
        return 0;
    }
    if(dp[idx][target]!=-1)return dp[idx][target];
    int take=0;
    int question=nums[idx][0],marks=nums[idx][1];
    for(int i=1;i<=question;i++){
        int score=i*marks;
        if(score<=target){
            take=((take)%mod+f(idx+1,target-score,nums)%mod)%mod;
        }
    }
    int notake=f(idx+1,target,nums)%mod;
    return dp[idx][target]=(take%mod+notake%mod)%mod;
}
    int waysToReachTarget(int target, vector<vector<int>>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,target,nums);
    }
};