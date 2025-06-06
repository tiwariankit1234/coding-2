class Solution {
public:

int dp[1002][1002][11];
int f(int idx,int target,vector<vector<int>>& queries,int numkiidx){
       int n=queries.size();
       if(target==0)return 0;
       if(target<0) return 1003;
       if(idx==n){
          return 1003;
       }
       if(dp[idx][target][numkiidx]!=-1)return dp[idx][target][numkiidx];
       int take=1003;
       if(queries[idx][0]<=numkiidx and queries[idx][1]>=numkiidx and target-queries[idx][2]>=0){
        take=1+f(idx+1,target-queries[idx][2],queries,numkiidx);
       }
       int notake=1+f(idx+1,target,queries,numkiidx);
       return dp[idx][target][numkiidx]=min(take,notake);
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int maxi=INT_MIN;
        memset(dp,-1,sizeof(dp));
         for(int i=0;i<n;i++){
            int k;
            if(nums[i]==0)
            k=0;
            else{
                k=f(0,nums[i],queries,i);
            }
            if(k>=1003)
            return -1;

            cout<<i<<" "<<k<<endl;
            maxi=max(k,maxi);
         }
       return maxi;
    }
};