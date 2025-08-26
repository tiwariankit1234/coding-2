class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        double area=INT_MIN,diagonal=INT_MIN;
        for(int i=0;i<m;i++){
            double newarea=grid[i][0]*grid[i][1];
            double newdiagonal=sqrt(grid[i][0]*grid[i][0]+grid[i][1]*grid[i][1]);
            if(newdiagonal>diagonal){
                diagonal=newdiagonal;
                area=newarea;
            }
            else if(newdiagonal==diagonal){
                area=max(area,newarea);
            }
        }
        return area;
    }
};