#define pii pair<int,int> 
class Solution {
public:

int dir[8][2]={{-1,0},{1,0},{1,1},{-1,-1},{0,1},{0,-1},{1,-1},{-1,1}};
bool isValid(int i,int j,int m,int n){
    return i>=0 and j>=0 and i<m and j<n;
}
int bfs(int node,vector<vector<int>>& grid){
    int m=grid.size(),n=grid[0].size();
    if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;

    queue<pii>q;
    vector<int>visited(m*n+n,0);
    q.push({1,0});
    visited[0]=1;
    while(q.size()){
        int cost=q.front().first;
        int node=q.front().second;
           int x = node / n, y = node % n;
           if(x==m-1 and y==n-1){
            return cost;
           }
        //    cout<<x<<" "<<y<<" "<<cost<<endl;
        q.pop();
        for(int k=0;k<8;k++){
            int newx=x+dir[k][0],newy=y+dir[k][1];
            // cout<<newx<<" "<<newy<<endl;
            if (isValid(newx, newy,m,n) and visited[newx*n+newy]==0 and grid[newx][newy]==0){ 
                // cout<<"visited"<<endl;
                //  cout<<newx<<" "<<newy<<" "<<cost<<endl;
                visited[newx*n+newy]=1;
                q.push({cost+1,newx*n+newy});
            }
        }
    }
    return -1;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(0,grid);
    }
};