class Solution {
public:
int dp[1002][12];
int countcol(int j,vector<vector<int>>&grid,int x){
     int m=grid.size(),n=grid[0].size();
     int ans=0;
    for(int i=0;i<m;i++){
       
       if(grid[i][j]!=x)
       ans++;
    }
    return ans;
}
int f(int j,vector<vector<int>>&grid,int prev){
    int m=grid.size(),n=grid[0].size();
    if(j==n)return 0;
    if(dp[j][prev+1]!=-1)return dp[j][prev+1];
    int ans=INT_MAX;
    for(int k=0;k<=9;k++){
        if(k!=prev){
         int count=countcol(j,grid,k);
           
           
            ans=min(ans,count+f(j+1,grid,k));
            
      
        }
    }
    return dp[j][prev+1]=ans;
}
    int minimumOperations(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,grid,-1);
    }
};