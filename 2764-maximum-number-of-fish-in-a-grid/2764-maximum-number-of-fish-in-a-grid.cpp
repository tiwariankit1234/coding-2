class Solution {
public:
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
bool isvalid(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&visited){
    int m=grid.size();
    int n=grid[0].size();
    if((row>=m || col>=n|| row<0||col<0) || grid[row][col]==0 || visited[row][col]==1)return false;
    else
    return true;
}
int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&visited){
   
    int m=grid.size();
    int n=grid[0].size();
    int count=grid[i][j];
    visited[i][j]=1;

    //   cout<<i<<" "<<j<<endl;
    for(int k=0;k<4;k++){
        int nrow=i+dir[k][0];
        int ncol=j+dir[k][1];
        // cout<<"nrow"<<nrow<<" "<<"ncol"<<ncol<<endl;
        if(isvalid(nrow,ncol,grid,visited)){
            // cout<<"nrow"<<nrow<<" "<<"ncol"<<ncol<<endl;
            count+=dfs(nrow,ncol,grid,visited);
        }
    }
  
    return count;

}


    int findMaxFish(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               
                if(grid[i][j] and visited[i][j]==0){
                    // cout<<"startpos"<<i<<" "<<"startpos"<<j<<endl;
                    count=max(count,dfs(i,j,grid,visited));
                }
            }
        }
        return count;
    }
};