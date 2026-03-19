class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int  m=grid.size(),n=grid[0].size(),count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(i>=1 and j>=0){
                    grid[i][j]=grid[i-1][j]+grid[i][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>=1){
                    grid[i][j]=grid[i][j]+grid[i][j-1];
                    
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<=k)count++;
            }
        }
      
        return count;
    }
};