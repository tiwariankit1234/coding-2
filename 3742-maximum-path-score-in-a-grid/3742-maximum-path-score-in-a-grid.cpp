int dp[201][201][1001];

class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    const int NEG_INF = -1e8;

    int f(int i, int j, int k) {
        if (k < 0 || i >= m || j >= n) return NEG_INF;

        if (i == m-1 && j == n-1) {
            if (grid[i][j] != 0)
                return dp[i][j][k] = (k >= 1) ? grid[i][j] : NEG_INF;
            else
                return dp[i][j][k] = grid[i][j];
        }

        if (dp[i][j][k] != (int)0x80808080) return dp[i][j][k];

        int cost;
        if (grid[i][j] != 0)
            cost = grid[i][j] + max(f(i+1, j, k-1), f(i, j+1, k-1));
        else
            cost = grid[i][j] + max(f(i+1, j, k), f(i, j+1, k));

        return dp[i][j][k] = cost;
    }

    int maxPathScore(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        grid = mat;

        // Only memset the slice you'll actually use
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                memset(dp[i][j], 0x80, (k + 1) * sizeof(int));

        int ans = f(0, 0, k);
        return ans >= 0 ? ans : -1;
    }
};