class Solution {
public:
 
 vector<int>dp1;
 
 vector<int>dp2,arr;


 
 void lengthOfLIS(vector<int>& nums) {
        arr=nums;
        int n=nums.size();
      dp1.resize(n,1);
  
    int ans=0;
      for(int i=0;i<nums.size();i++){
          for(int j=0;j<=i-1;j++){
              if(arr[j]<arr[i])
              dp1[i]=max(dp1[i],1+dp1[j]);
          }
   
      ans=max(ans,dp1[i]);
      }
   
    
      return ;
    }

     void lengthOfLDS(vector<int>& nums) {
        arr=nums;
        int n=nums.size();
      dp2.resize(n,1);
  
      int ans=0;
      for(int i=n-2;i>=0;i--){
        
          for(int j=n-1;j>=i+1;j--){
              if(arr[j]<arr[i])
              dp2[i]=max(dp2[i],1+dp2[j]);
          }
   
      ans=max(ans,dp2[i]);
      
      } 
   
    
      return ;
    }





    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();

        int minimumsteps=INT_MAX;
         
         lengthOfLIS(nums);

         for(auto it:dp1)
         cout<<it<<" ";

         cout<<endl;
         lengthOfLDS(nums);

         for(auto it:dp2)
         cout<<it<<" ";

         cout<<endl;
        for(int i=0;i<n;i++){
            minimumsteps=min(minimumsteps,n+1-(dp1[i]+dp2[i]));
        }
         
         return minimumsteps;
    }
};