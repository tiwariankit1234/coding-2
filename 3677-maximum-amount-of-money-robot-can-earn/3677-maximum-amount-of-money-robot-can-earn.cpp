class Solution {
public:
    int solve(int i, int j, int canNeutralize, vector<vector<int>>& coins,
              vector<vector<vector<int>>>& dp) {
        int m = coins.size();
        int n = coins[0].size();

        if (i >= m || j >= n)
            return -1e9;
        if (i == m - 1 && j == n - 1) {
            return (coins[i][j] < 0 && canNeutralize > 0) ? 0 : coins[i][j];
        }
        if (dp[i][j][canNeutralize] != INT_MIN) {
            return dp[i][j][canNeutralize];
        }

        int ans = -1e9;

        if (coins[i][j] < 0) {
            if (canNeutralize > 0) {
                ans = max(ans,
                          max(solve(i + 1, j, canNeutralize - 1, coins, dp),
                              solve(i, j + 1, canNeutralize - 1, coins, dp)));
            }
        }

                    ans=max(ans,max(coins[i][j]+solve(i+1,j,canNeutralize,coins,dp),coins[i][j]+solve(i,j+1,canNeutralize,coins,dp)));

        dp[i][j][canNeutralize] = ans;

        return dp[i][j][canNeutralize];
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(0, 0, 2, coins, dp);
    }
};