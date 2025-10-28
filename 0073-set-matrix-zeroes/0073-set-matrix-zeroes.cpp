class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        bool iszerorow=false,iszerocol=false;
        for(int i=0;i<n;i++){
            if(grid[0][i]==0)iszerorow=true;
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                iszerocol=true;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==0){
                    grid[i][0]=0;
                    grid[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][0]==0 ||grid[0][j]==0){
                    grid[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(iszerocol)grid[i][0]=0;
        }
        for(int j=0;j<n;j++){
            if(iszerorow)grid[0][j]=0;
        }
          return ;
        
    }
};