class Solution {
public:
int dp[101][101];
int f(int idx,int startime,int time,vector<vector<int>>& nums){
    if(startime>=time){
        return 0;
    }
    if(idx==nums.size())
    return 9000;
    if(dp[idx][startime]!=-1)return dp[idx][startime];
    int ans=INT_MAX;
    // int take
    if(startime>=nums[idx][0]){
        int newstartime=0;
        newstartime=nums[idx][1];
        ans=min(ans,1+f(idx+1,newstartime,time,nums));
    }
    else if((startime<nums[idx][0]))
    return 9000;
    // skip
    ans=min(ans,f(idx+1,startime,time,nums));
    return dp[idx][startime]=ans;
}
    int videoStitching(vector<vector<int>>& nums, int time) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
       return  f(0,0,time,nums)==9000?-1:f(0,0,time,nums);
    }
};