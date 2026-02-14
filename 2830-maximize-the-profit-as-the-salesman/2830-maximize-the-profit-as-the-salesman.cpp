class Solution {
public:
int dp[100006];
vector<int>precompute;
int f(int idx,vector<vector<int>>& offers){
    int n=offers.size();
    // cout<<idx<<endl;
    if(idx==n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int futidx=upper_bound(precompute.begin()+idx,precompute.end(),offers[idx][1])-precompute.begin();
    int take=offers[idx][2]+f(futidx,offers);
    int notake=f(idx+1,offers);
    return dp[idx]=max(take,notake);
}
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        memset(dp,-1,sizeof(dp));
        sort(offers.begin(),offers.end());
        for(auto it:offers){
            precompute.push_back(it[0]);
        }
        return f(0,offers);
    }
};