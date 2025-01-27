class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        int m = grid.size();
        int n = grid[0].size();

        // Base cases
        if (i >= m || j >= n) return INT_MAX; // Out of bounds
        if (i == m - 1 && j == n - 1) { // Bottom-right cell
            return grid[i][j] > 0 ? 1 : -grid[i][j] + 1;
        }

        // If the result is already computed
        if (memo[i][j] != -1) return memo[i][j];

        // Recursive calls for the next cells (down and right)
        int down = f(i + 1, j, grid, memo);
        int right = f(i, j + 1, grid, memo);

        // Minimum health needed to move forward
        int ans = min(down, right) - grid[i][j];
        memo[i][j] = (ans <= 0) ? 1 : ans; // If positive or zero, return 1; otherwise, return absolute health needed

        return memo[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1)); // Initialize memoization table
        return f(0, 0, grid, memo);
    }
};
