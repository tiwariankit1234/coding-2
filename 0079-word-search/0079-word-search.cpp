class Solution {
public:
bool f(int i,int j,string &s,string& word,vector<vector<bool>>&visited,vector<vector<char>>& grid){
      int m=grid.size(),n=grid[0].size();
     if(s.size()==word.size()){
        return s==word;
     }
   
     if(i>=m ||i<0||j<0||j>=n||visited[i][j]==true) return  false;
       bool ans=false;
       visited[i][j]=true;
      s+=grid[i][j];
      ans=ans||f(i+1,j,s,word,visited,grid)||f(i,j+1,s,word,visited,grid)
    ||f(i-1,j,s,word,visited,grid)||f(i,j-1,s,word,visited,grid);
       visited[i][j]=false;
       s.pop_back();
     return ans;

}
    bool exist(vector<vector<char>>& grid, string word) {
       
        int m=grid.size(),n=grid[0].size();
         vector<vector<bool>>visited(m,vector<bool>(n,false));
         string s="";
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==word[0] and f(i,j,s,word,visited,grid)){
                    return true;
                }
            }
        }
        return false;
    }
};