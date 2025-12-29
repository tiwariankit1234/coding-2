class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),i=0,j=n-1;
        int count=0;
        while(i>=0 and j>=0 and i<m and j<n){
            if(grid[i][j]<0){
                count+=m-i;
                j--;
            }
            else{
                i++;
            }
        }
        return count;

    }
};