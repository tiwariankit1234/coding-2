class Solution {
public:


      int dp[1005][1004];
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        for(auto &x:nums)
        x=x%k;

        // for(auto it:nums)
        // cout<<it<<" ";

        cout<<endl;
        int ans=INT_MIN;
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<nums.size();i++){
          for(int j=0;j<=i-1;j++){
              int difference=(nums[i]+nums[j])%k;
               if((dp[j][difference]+1)>dp[i][difference]){
                dp[i][difference]=1+dp[j][difference];
                ans=max(ans,dp[i][difference]);
              }
          }
        }   
          return ans+2;

    }
};