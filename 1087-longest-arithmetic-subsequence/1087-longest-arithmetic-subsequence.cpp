class Solution {
public:


int dp[1002][1002];

    int longestArithSeqLength(vector<int>& nums) {
      
       memset(dp,sizeof(dp),1);
  
      int ans=2;
      for(int i=0;i<nums.size();i++){
          for(int j=0;j<=i-1;j++){
              int difference=nums[i]-nums[j]+500;
              if(dp[j][difference]>1){
                dp[i][difference]=1+dp[j][difference];
                ans=max(ans,dp[i][difference]);
              }
              else{
                dp[i][difference]=2;
              }
          }
      
     
      }
   
    
      return ans;
    }
};