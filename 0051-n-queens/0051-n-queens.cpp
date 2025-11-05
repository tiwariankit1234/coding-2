class Solution {
public:
vector<int>leftrow,lowerdiagonal,upperdiagonal;
 vector<vector<string>>ans;
void f(int col,vector<string>&board){
    int n=board.size();
    if(col==n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 and lowerdiagonal[row+col]==0 and upperdiagonal[n-1+row-col]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            lowerdiagonal[row+col]=1;
            upperdiagonal[n-1+row-col]=1;
            f(col+1,board);
              board[row][col]='.';
            leftrow[row]=0;
            lowerdiagonal[row+col]=0;
            upperdiagonal[n-1+row-col]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        leftrow.clear();
        leftrow.resize(n,0);
        lowerdiagonal.clear();
        lowerdiagonal.resize(2*n-1,0);
        upperdiagonal.clear();
        upperdiagonal.resize(2*n-1,0);
        vector<string>board(n,string(n,'.'));
        f(0,board);
        return ans;

    }
};