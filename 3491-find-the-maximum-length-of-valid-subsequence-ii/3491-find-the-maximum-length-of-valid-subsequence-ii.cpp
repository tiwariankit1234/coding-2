class Solution {
public:
// //For any DP problem, always list down the variables you have
// See if any of the variable can alone be a state variable and can solve the answer for all the indices without dependent on another variable. If Yes, then it can be 1D DP

// If 1D is not possible, add the dependent variable to the state - 2D DP
// Look for all the combinations of the variables to for a 2D DP

// Then write down the relation,

// dp[i][j] = dp[i - 1][..] or dp[i+1][..]

// Based on it, pre-fill the base cases,
// iterate and fill the DP table

// Same strategy for 3D DP

     
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