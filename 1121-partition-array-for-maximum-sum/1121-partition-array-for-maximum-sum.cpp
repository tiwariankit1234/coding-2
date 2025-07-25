class Solution {
public:
int dp[502];
// try all partions 
// no need of end 
// always the variable will change the state 
// there will be no fixed loop occur in loop
// like start+k
int f(int start,int end,int k,vector<int>& arr){
   int n=arr.size();
   if(start==n)return 0;
   if(dp[start]!=-1)return dp[start];
   int maxsum=0;
   int maxelement=0;
   for(int i=start;i<min(n,start+k);i++){
     maxelement=max(arr[i],maxelement);
     maxsum=max(maxsum,maxelement*(i-start+1)+f(i+1,end,k,arr));
   }
   return dp[start]=maxsum;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,k,arr);
    }
};