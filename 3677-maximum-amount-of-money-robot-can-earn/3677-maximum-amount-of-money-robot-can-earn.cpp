class Solution {
public:
    int solve(int i, int j, int canNeutralize, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        int m = coins.size();
        int n = coins[0].size();

        if (i >= m || j >= n) return -1000000;
        if (i == m - 1 && j == n - 1) {
            return (coins[i][j] < 0 && canNeutralize > 0) ? 0 : coins[i][j];
        }

        if (dp[i][j][canNeutralize] != -1) {
            return dp[i][j][canNeutralize];
        }

        int right = -1000000, down = -1000000;

        if (coins[i][j] < 0) {
            if (canNeutralize > 0) {
                right = solve(i, j + 1, canNeutralize - 1, coins, dp);
                down = solve(i + 1, j, canNeutralize - 1, coins, dp);
            }

            right = max(right, solve(i, j + 1, canNeutralize, coins, dp) + coins[i][j]);
            down = max(down, solve(i + 1, j, canNeutralize, coins, dp) + coins[i][j]);
        } else {
            right = solve(i, j + 1, canNeutralize, coins, dp) + coins[i][j];
            down = solve(i + 1, j, canNeutralize, coins, dp) + coins[i][j];
        }

        dp[i][j][canNeutralize] = max(right, down);
        return dp[i][j][canNeutralize];
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1)));
        return solve(0, 0, 2, coins, dp);
    }
};