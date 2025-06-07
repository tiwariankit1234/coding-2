class Solution {
public:

    bool f(int idx, vector<int>& nums,vector<int>&dp) {
       
        int n=nums.size();
        
        if (idx == n){
            return 1;
        }
          
           
            if(dp[idx]!=-1)
            {
                return dp[idx];
            }
            bool ans=false;
        if (idx<=(n-2)) {
            if (nums[idx] == nums[idx + 1]) {
                ans=ans||f(idx+2,nums,dp);
            }
        }
        if(idx<=(n-3)){
            if(nums[idx] == nums[idx+1] and nums[idx+1]==nums[idx+2]){
                ans=ans||f(idx+3,nums,dp);
            } 
        }
        if(idx<=(n-3)){
            if(nums[idx]+1==nums[idx+1] and nums[idx+1]+1==nums[idx+2]){
                ans=ans||f(idx+3,nums,dp);
            }
        }
        return dp[idx]=ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
         
        return f(0, nums,dp);
    }
};