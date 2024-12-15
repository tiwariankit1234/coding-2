//https://leetcode.com/problems/surrounded-regions/
class Solution {
public:
   int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;

//  boundry traversal
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                // board[0][j]='2';
            }
            if(board[m-1][j]=='O')
            {
                q.push({m-1,j});
                // board[m-1][j]='2';
            }
        }

for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                // board[i][0]='2';
            }
            if(board[i][n-1]=='O')
            {
                q.push({i,n-1});
                // board[i][n-1]='2';
            }
        }


    // bfs
    int row=0,col=0;
    while(q.size()>0){
        auto [row,col]=q.front();
        q.pop();
        board[row][col]='2';  //making visited 
        for(int i=0;i<4;i++){
            int nrow=row+dir[i][0];
            int ncol=col+dir[i][1];
      if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and board[nrow][ncol]=='O'){

q.push({nrow,ncol});  //insertion of connected zero
      }
        }

    }

 for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O')
            board[i][j]='X';    // converting  all the 'O' to X because they are not connected by boundry O cells 
        }
    }



    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='2')
            board[i][j]='O';      // back connected zero by unvisiting
        }
    }

    
}
};