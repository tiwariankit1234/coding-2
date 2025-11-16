class Solution {
public:
int dp[102][102];
int f(int i,int j,vector<int>&cuts){
      
      if((j-i)<=1)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
     int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
     
       ans=min(ans,cuts[j]-cuts[i]+f(i,k,cuts)+f(k,j,cuts));
    }
    return dp[i][j]=ans;
}
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return f(0,cuts.size()-1,cuts);
    }
};