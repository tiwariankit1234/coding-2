class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& points) {
        unordered_map<int,int>up,down,left,right;
        int count=0;
        // for y direction
        for(auto it:points){
            int x=it[0],y=it[1];
            left[y]=INT_MAX;
            down[x]=INT_MAX;
        }
        for(auto it:points){
            int x=it[0],y=it[1];
           
            left[y]=min(x,left[y]);
            right[y]=max(x,right[y]);
            up[x]=max(y,up[x]);
            down[x]=min(y,down[x]);
        }
        
        for(auto it:points){
            int x=it[0],y=it[1];
            int leftpoint=left[y];
            int rightpoint=right[y];
            int upperpoint=up[x],lowerpoint=down[x];
            
            if(leftpoint!=0 and leftpoint<x and rightpoint!=0 and rightpoint>x and upperpoint!=0 and upperpoint>y and lowerpoint!=0 and lowerpoint<y)count++;
        }
        return count;
    }
};