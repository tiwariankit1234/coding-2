class Solution {
public:


    int longestSubsequence(vector<int>& nums, int k) {
      
         unordered_map<int,int>dp;
         // storing the largest length at each index
         
  
         int ans=1;
      for(int i=0;i<nums.size();i++){
        int num=nums[i];
        int required=num-k;
        if(dp.find(required)!=dp.end()){
            dp[num]=dp[required]+1;
          
        }
        else{
            dp[num]=1;
        }

        ans=max(ans,dp[num]);
   
    
      }
      return ans;
    }
};