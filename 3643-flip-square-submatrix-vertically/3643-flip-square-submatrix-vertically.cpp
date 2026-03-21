class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>mat=grid;
        int p=x;
       for(int i=x+k-1;i>=x;i--){
           int l=y+k;
           for(int j=y;j<l;j++){
             mat[p][j]=grid[i][j];
           }
           p++;
       }
        return mat;
    }
};