class Solution {
public:
int dp[502];
int f(int i,vector<int>&arr,int m){
  
    int n=arr.size();
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=INT_MIN;
    int maxi=INT_MIN;
    int temp=0;
    for(int k=i;k<=min((i+m-1),n-1);k++){
        
        maxi=max(maxi,arr[k]);
        temp=maxi*(k-i+1)+f(k+1,arr,m);
        ans=max(temp,ans);
    }
    return dp[i]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,arr,k);
    }
};