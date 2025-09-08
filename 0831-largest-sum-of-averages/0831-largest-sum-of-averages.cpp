class Solution {
public:
double dp[105][103];
double f(int idx,vector<int>&nums,int k){
    int n=nums.size();
    if(idx==n and k<0)return -1e5*1.0;
    if(idx==n)return 0.0;
    if(k<=0)return -1e5*1.0;
    
    if(dp[idx][k]>=0.0)return dp[idx][k];
     double sum=0,maxsum=0;
    for(int start=idx;start<n;start++){
        sum+=nums[start];
        double average=sum*1.0/(start-idx+1)*(1.0);
        maxsum=max(maxsum,average+f(start+1,nums,k-1));
    }
    return dp[idx][k]=maxsum;

}
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));

        return f(0,nums,k);
    }
};