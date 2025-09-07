class Solution {
public:
int dp[302][302];
int f(int i,int j,vector<int>&nums){
    if(i>j)return 0;

   if(i==j)return nums[i-1]*nums[i]*nums[j+1];
   if(dp[i][j]!=-1)return dp[i][j];
   int cost=INT_MIN;
   for(int k=i;k<=j;k++){
    cost=max(cost,nums[k]*nums[i-1]*nums[j+1]+f(i,k-1,nums)+f(k+1,j,nums));
   }
   return dp[i][j]=cost;
}
    int maxCoins(vector<int>& nums) {
       memset(dp,-1,sizeof(dp));
       nums.insert(nums.begin(),1);
       nums.push_back(1);
        int n=nums.size();
       return f(1,n-2,nums);
        
    }
};