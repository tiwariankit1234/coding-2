#define tup tuple<int,int,int>
class Solution {
public:
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int f(vector<vector<int>>&grid){
    int m=grid.size(),n=grid[0].size();
    priority_queue<tup,vector<tup>,greater<tup>>pq;
   vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
    int leastcost=INT_MIN;
    pq.push({grid[0][0],0,0});
    while(pq.size()){
        auto [cost,row,col]=pq.top();
        leastcost=max(cost,leastcost);
        pq.pop();
        // cout<<cost<<" "<<row<<" "<<col<<endl;
        if(row==m-1 and col==n-1)return leastcost;
        for(int k=0;k<4;k++){
            int newr=row+dir[k][0],newc=col+dir[k][1];
            if(newr>=0 and newr<m and newc>=0 and newc<n and cost<dist[newr][newc]){
             pq.push({grid[newr][newc],newr,newc});
             dist[newr][newc]=cost;
            }
        }
    }
    return leastcost;

}
    int swimInWater(vector<vector<int>>& grid) {
      
        return f(grid);

    }
};