class Solution {
public:
int dp[501][26][601];
int f(int idx,int k,int prev,vector<int>&nums){
    int n=nums.size();
    if(idx==n)return 0;
   if(dp[idx][k][prev+100]!=-1)return dp[idx][k][prev+100];
    int take=0,notake=0;
   
   if(prev==-1 ||nums[idx]==nums[prev]){
        take=1+f(idx+1,k,idx,nums);
    }
     else if(nums[idx]!=nums[prev] and k>0){
        take=1+f(idx+1,k-1,idx,nums);
    }
    notake=f(idx+1,k,prev,nums);
    return dp[idx][k][prev+100]=max(take,notake);
}
    int maximumLength(vector<int>& nums, int k) {
        int maxlength=0;
        memset(dp,-1,sizeof(dp));
       for(int i=0;i<=k;i++){
          maxlength=max(maxlength,f(0,k,-1,nums));
       }
       return maxlength;
    }
};