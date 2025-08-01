class Solution {
public:
int dp[1002][1003];
int f(int ext,int idx,vector<int>&nums){
    int n=nums.size();
    // for single element 
    if(idx==nums.size())return nums[ext];
    // for two elements
    if(idx==nums.size()-1)return max(nums[ext],nums[idx]);
    if(dp[ext][idx]!=-1)return dp[ext][idx];
    cout<<nums[ext]<<" "<<nums[idx]<<" "<<ext<<" "<<idx<<endl;
    int m=max(nums[ext],nums[idx])+f(idx+1,idx+2,nums);
    int k=max(nums[idx],nums[idx+1])+f(ext,idx+2,nums);
    int t=max(nums[ext],nums[idx+1])+f(idx,idx+2,nums);
    return dp[ext][idx]=min({m,k,t});
    

     
}
    int minCost(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(0,1,nums);
    }
};