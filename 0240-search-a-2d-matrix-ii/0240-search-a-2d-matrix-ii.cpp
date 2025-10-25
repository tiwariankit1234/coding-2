class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        int x=0,y=n-1;
          while(x<m and y>=0){
            if(mat[x][y]==target)return true;
            else if(mat[x][y]>target)y--;
            else
            x++;
          }
          return false;
    }
};