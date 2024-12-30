class Solution {
public:
    long long dp[100001][4][3]; // Memo table for DP

    long long count(int index, string &s, int size, int last) {
        if (index >= s.size()) {
            return size == 3 ? 1 : 0;
        }

        if (dp[index][size][last] != -1) {
            return dp[index][size][last];
        }

        long long ways = 0;

        // Option 1: Include current character if valid
        if (size < 3 && (size == 0 || s[index] - '0' != last)) {
            ways += count(index + 1, s, size + 1, s[index] - '0');
        }

        // Option 2: Skip current character
        ways += count(index + 1, s, size, last);

        return dp[index][size][last] = ways;
    }

    long long numberOfWays(string s) {
        memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
        return count(0, s, 0, 2);   // Start with index 0, size 0, and invalid last character
    }
};