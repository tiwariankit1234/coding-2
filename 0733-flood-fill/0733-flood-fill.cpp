class Solution {
public:
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int color) {
        if(mat[sr][sc]==color)return mat;
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0)),ans=mat;
        int prevcol=mat[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        while(q.size()){
            auto [row,col]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int newrow=row+dir[k][0],newcol=col+dir[k][1];
                if(newrow>=0 and newrow<m and newcol>=0 and newcol<n and visited[newrow][newcol]==0  and mat[newrow][newcol]==prevcol){
                   visited[newrow][newcol]=1;
                   q.push({newrow,newcol});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==1){
                    ans[i][j]=color;
                }
                else if(visited[i][j]==0){
                    ans[i][j]=mat[i][j];
                }
            }
        }
        return ans;
    }
};