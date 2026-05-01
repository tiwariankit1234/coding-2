  int dp[201][201][403];

class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
  

    int f(int i, int j, int k) {
        if (k < 0) return -1e7;
        if (i >= m || j >= n) return -1e7;

        if (i == m-1 && j == n-1) {
            if (grid[i][j] != 0)
                return dp[i][j][k] = (k >= 1) ? grid[i][j] : -1e7;
            else
                return dp[i][j][k] = grid[i][j]; // k>=0 always true
        }

        if (dp[i][j][k] != -10000007) return dp[i][j][k];

        int cost = 0;
        if (grid[i][j] != 0)
            cost = grid[i][j] + max(f(i+1, j, k-1), f(i, j+1, k-1));
        else
            cost = grid[i][j] + max(f(i+1, j, k), f(i, j+1, k));

        return dp[i][j][k] = cost;
    }

    int maxPathScore(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        grid = mat;
        
        k=min(402,k);
        for (int i = 0; i < 201; i++)
            for (int j = 0; j < 201; j++)
                for (int k = 0; k < 403; k++)
                    dp[i][j][k] = -10000007;

        int ans = f(0, 0, k);
        return ans >= 0 ? ans : -1;
    }
};