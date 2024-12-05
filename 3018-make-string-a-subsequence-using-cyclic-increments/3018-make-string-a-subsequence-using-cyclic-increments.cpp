class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        
        // DP table
        vector<vector<bool>> dp(n2 + 1, vector<bool>(n1 + 1, false));

        // Base cases
        for (int j = 0; j <= n1; j++) dp[0][j] = true; // Empty s2 is a subsequence of any prefix of s1

        // Fill DP table
        for (int i = 1; i <= n2; i++) {
            for (int j = 1; j <= n1; j++) {
                if (s1[j - 1] == s2[i - 1] || ((s1[j - 1] - 'a' + 1) % 26) == (s2[i - 1] - 'a')) {
                    dp[i][j] = dp[i - 1][j - 1]; // Match and move both pointers
                } else {
                    dp[i][j] = dp[i][j - 1]; // Skip s1[j-1] and move in s1
                }
            }
        }

        // Return final result
        return dp[n2][n1];
    }
};
