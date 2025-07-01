class Solution {
public:
int dp[251][251];
int f(int idx,int k,vector<int>&nums){
    int n=nums.size();
    // if only one subarray is there 
    if(k==1){
        int minixor=0;
        for(int j=idx;j<nums.size();j++){
            minixor^=nums[j];
        }
        // cout<<"return "<<" "<<endl;
        // cout<<idx<<" "<<k<<" "<<minixor<<endl;
        return dp[idx][k]=minixor;
    }
    if(dp[idx][k]!=-1)return dp[idx][k];
    int newxor=0;
    int minxor=INT_MAX;
    // create different partitions

    for(int j=idx;j<=(n-k);j++){
     newxor^=nums[j];
     minxor=min(minxor,max(newxor,f(j+1,k-1,nums)));
    }
    // cout<<idx<<" "<<k<<" "<<minxor<<endl;
    return dp[idx][k]=minxor;
}
    int minXor(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return f(0,k,nums);
    }
};