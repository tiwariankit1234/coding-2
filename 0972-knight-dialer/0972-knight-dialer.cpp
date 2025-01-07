class Solution {
public:
int dir[8][2]={{2,-1},{2,1},{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2}};
int mod=1e9+7;
int dp[4][3][5002];

int f(int i,int j,vector<vector<int>>&grid,int ways){
    int m=grid.size();
    int n=grid[0].size();
    if(i>=m ||j>=n||i<0||j<0)return 0;
    if(i==3 and (j==0 || j==2))return 0;
    if(ways==0){
        return 1;
    }
    
    if(dp[i][j][ways]!=-1)return dp[i][j][ways];
    int countways=0;
    for(int k=0;k<8;k++){
       countways=(countways+f(i+dir[k][0],j+dir[k][1],grid,ways-1))%mod;
    }
    return dp[i][j][ways]=countways;
}
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>grid(4,vector<int>(3,0));
        grid[3][0]=1;
          grid[3][2]=1;
          int countways=0;
          int ways=n-1;
          for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==1){
                    continue;
                }
                else{
                    countways=(countways+f(i,j,grid,ways))%mod;
                }
            }
          }
          return countways;
    }
};