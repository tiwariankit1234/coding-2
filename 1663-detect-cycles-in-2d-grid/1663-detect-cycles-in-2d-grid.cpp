class Solution {
public:
int dir[4][2]={{-1,0},{0,1},{0,-1},{1,0}};

bool bfs(int i,int j,char ch,vector<vector<char>>&grid,vector<vector<bool>>&visited){
    int m=grid.size(),n=grid[0].size();
   
    visited[i][j]=true;
   queue<pair<pair<int,int>,pair<int,int>>>q;
   q.push({{i,j},{-1,-1}});
   while(q.size()){
     auto [x,y]=q.front().first;
     auto [p,r]=q.front().second;
     q.pop();
   
     
    //  cout<<x<<" "<<y<<" "<<p<<" "<<r<<" "<<ch<<endl;
     for(int k=0;k<4;k++){
        int newx=x+dir[k][0],newy=y+dir[k][1];
        if(newx>=0 and newx<m and newy>=0 and newy<n and grid[newx][newy]==ch and  visited[newx][newy]==false){
               q.push({{newx,newy},{x,y}});
                visited[newx][newy]=true;
        }
        else if(newx>=0 and newx<m and newy>=0 and newy<n and grid[newx][newy]==ch and visited[newx][newy]==true and (!(newx==p and newy==r))){
            return true;
        }
     }
   }

    // cout<<i<<" "<<j<<" "<<i<<" "<<j<<" "<<ch<<endl;
       return false;
} 
    bool containsCycle(vector<vector<char>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
             vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                
                if(visited[i][j]==false and bfs(i,j,grid[i][j],grid,visited) ){
                
                return true;
                }
                else{
                    cout<<i<<" "<<j<<endl;
                }

                }
            }
        
        return false;
    }
};