class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));

        for(int j=0;j<cols;j++)
        {
            if(matrix[0][j]==1)
            dp[0][j]=1;
        }

        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0]==1)
            dp[i][0]=1;
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==1){
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }

      int count=0;
      for(auto it:dp){
        for(auto k:it){
            count+=k;
        }
      }
      return count;
    }
};