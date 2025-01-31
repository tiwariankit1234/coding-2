class Solution {
public:
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool isValid(vector<vector<int>>&grid,int nrow,int ncol,vector<vector<int>>&visited){
    int m=grid.size(),n=grid[0].size();
    return nrow>=0 and nrow<m and ncol>=0 and ncol<n and visited[nrow][ncol]==0 and grid[nrow][ncol]==1;
}
int color_dfs(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&visited,int islandid){
    visited[i][j]=islandid;
    int count=1;
    for(int k=0;k<4;k++){
        int nrow=i+dir[k][0];
        int ncol=j+dir[k][1];
        if(isValid(grid,nrow,ncol,visited)){
          count+=color_dfs(grid,nrow,ncol,visited,islandid);
        }
    }
     return count;
}
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int islandid=2;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] and visited[i][j]==0){
                  
                   mp[islandid]=color_dfs(grid,i,j,visited,islandid);
                   islandid++;
                }
            }
        }

        // cnt total ones 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j])
                cnt++;
            }
        }
        
        if(cnt==m*n)return m*n;
            int maxans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int ans=0;
                 unordered_set<int>s;
                 for(int k=0;k<4;k++){
                       int nrow=i+dir[k][0];
                     int ncol=j+dir[k][1];
                 if(nrow>=0 and nrow<m and ncol>=0 and ncol<n){
                     int id=visited[nrow][ncol];
                        if(s.find(id)==s.end()){
                           ans+=mp[id];
                           s.insert(id);
                        }
                     }
                }
                maxans=max(ans+1,maxans);
            }
        }
    }
    return maxans;
    }
};