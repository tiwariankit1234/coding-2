class Solution {
public:
int dp[302][302];
int f(int i,int j,vector<int>&nums){
      if(i>j)return 0;
      if(i==j){
        return nums[i-1]*nums[i]*nums[i+1];
      }
      if(dp[i][j]!=-1)return dp[i][j];
     int ans=INT_MIN;
    for(int k=i;k<=j;k++){
       ans=max(ans,nums[i-1]*nums[j+1]*nums[k]+f(i,k-1,nums)+f(k+1,j,nums));
    }
    return dp[i][j]=ans;
}
    int maxCoins(vector<int>& nums) {
         int n=nums.size();
         memset(dp,-1,sizeof(dp));
         vector<int>arr(n+2);
         arr[0]=1;
         arr[n+1]=1;
         int k=1;
         for(int i=0;i<n;i++){
            arr[k++]=nums[i];
         }
         arr[n+1]=1;
        //  for(auto it:arr)
        //   cout<<it<<" ";
        //   cout<<endl;
         return f(1,arr.size()-2,arr);
    }
};