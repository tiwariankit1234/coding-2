class Solution {
public:


     
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        for(auto &x:nums)
        x=x%k;

        // for(auto it:nums)
        // cout<<it<<" ";

        // cout<<endl;
        int ans=INT_MIN;
       vector<vector<int>>dp(1005,vector<int>(1005,1));

        for(int i=0;i<nums.size();i++){
          for(int j=0;j<=i-1;j++){
              int difference=(nums[i]+nums[j])%k;
               if((dp[j][difference]+1)>dp[i][difference]){
                dp[i][difference]=1+dp[j][difference];
                // cout<<dp[j][difference]<<" "<<dp[i][difference]<<endl;
                ans=max(ans,dp[i][difference]);
              }
          }
        }   
          return ans;

    }
};