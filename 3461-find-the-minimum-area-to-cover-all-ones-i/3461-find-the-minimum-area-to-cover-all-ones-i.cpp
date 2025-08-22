class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int leftmostx=0,rightmostx=0,leftymin=INT_MAX,rightymax=INT_MIN;
  

        bool flag=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !flag){
                    leftmostx=i;
                    flag=true;
                }
                  if(grid[i][j]==1){
                    rightmostx=i;
                  }
                  if(grid[i][j]==1){
                    leftymin=min(leftymin,j);
                    rightymax=max(rightymax,j);
                  }
            }
        }
        int area=(rightmostx-leftmostx+1)*(rightymax-leftymin+1);
         return area;
    }
};