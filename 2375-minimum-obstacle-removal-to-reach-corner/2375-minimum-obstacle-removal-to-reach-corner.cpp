#define pii  pair<int, pair<int,int>>


class Solution {
public:
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int f(vector<vector<int>>& grid){
    int m=grid.size(),n=grid[0].size();

  priority_queue<pii,vector<pii>,greater<pii>>pq;
  pq.push({0,{0,0}});
 vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
  dist[0][0]=0;
  while(pq.size()){
    auto [cost,node]=pq.top();
    int x=node.first,y=node.second;
    pq.pop();
    for(int k=0;k<4;k++){
        int newx=x+dir[k][0],newy=y+dir[k][1];
        if(newx>=0 and newy>=0 and newx<m and newy<n  ){
            if(grid[newx][newy]==1){
               if(dist[x][y]+1<dist[newx][newy]){
                dist[newx][newy]=dist[x][y]+1;
                pq.push({dist[x][y]+1,{newx,newy}});
               }
            }
            else{
                if(dist[x][y]<dist[newx][newy]){
                    dist[newx][newy]=dist[x][y];
                    pq.push({dist[x][y],{newx,newy}});
                }
            }
        }
    }
  }
  return dist[m-1][n-1];
}
    int minimumObstacles(vector<vector<int>>& grid) {
        return f(grid);
    }
};