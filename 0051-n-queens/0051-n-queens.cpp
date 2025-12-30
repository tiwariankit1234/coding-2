class Solution {
public:
bool isvalid(int idx,int j,vector<string>&board){
    int m=board.size(),n=board[0].size();
    // col check
    for(int i=0;i<n;i++){
        if(board[i][j]=='Q')return false;
    }
    // leftdiagonal check
    int p=idx-1,q=j-1;
    while(p>=0 and q>=0){
        if(board[p][q]=='Q')return false;
        p--;
        q--;
    }
    // right diagonal check
    p=idx-1,q=j+1;
    while(p>=0 and q<n){
        if(board[p][q]=='Q')return false;
        p--;
        q++;
    }
    return true;

}
void f(int idx,vector<string>&board,vector<vector<string>>&ans,int n){
  if(idx==n){
    ans.push_back(board);
    return ;
  }
   int k=board[idx].size();
    for(int j=0;j<n;j++){
      if(isvalid(idx,j,board)){
      board[idx][j]='Q';
      f(idx+1,board,ans,n);
      board[idx][j]='.';
      }
    }

    return ;
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        f(0,board,ans,n);
        return ans;
    }
};