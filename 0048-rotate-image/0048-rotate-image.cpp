class Solution {
public:
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> result(n, vector<int>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}


    void rotate(vector<vector<int>>& matrix) {
        matrix=transpose(matrix);
       int i=0,j=matrix[0].size()-1;
      for(int i=0;i<matrix.size();i++)reverse(matrix[i].begin(),matrix[i].end());
      return ;
    }
};