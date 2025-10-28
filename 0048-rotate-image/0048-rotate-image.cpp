class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(grid[i].begin(),grid[i].end());
        }
        return ;
    }
};