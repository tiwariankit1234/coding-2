class Solution {
public:
int dp[101][101];
int f(int i,int j,vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    if(i==(m-1) and (j==(n-1))){
        if(grid[i][j]==0)return 1;
        else
        return 0;
    }
    if(i==m || j==n)return 0;
    if(grid[i][j]==1)return 0;
     if(dp[i][j]!=-1)return dp[i][j];
     return dp[i][j]=(f(i,j+1,grid)+f(i+1,j,grid));
}


    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        memset(dp,-1,sizeof(dp));
        return f(0,0,grid);
    }
};