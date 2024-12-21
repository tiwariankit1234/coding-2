


class Solution {
public:



int mod=1e9+7;

int dp[302][302][16];

int f(int i,int j,int ans,vector<vector<int>>&mat,int k){
    int m=mat.size(),n=mat[0].size();
    if(i<0 || j<0|| i>=m || j>=n)return 0;
 if(i==(m-1)and (j==(n-1))){
     int nextxor=ans^(mat[m-1][n-1]);
     if(nextxor==k)
        return 1;
     return 0;
 }
    if(dp[i][j][ans]!=-1)return dp[i][j][ans];

    int newxor=(ans ^ mat[i][j]);
     
  
   dp[i][j][ans]=(f(i,j+1,newxor,mat,k)%mod+f(i+1,j,newxor,mat,k)%mod)%mod;
   

    return dp[i][j][ans];
}


    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
     int m=grid.size(),n=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
         
        return f(0,0,0,grid,k);
    
    }
};