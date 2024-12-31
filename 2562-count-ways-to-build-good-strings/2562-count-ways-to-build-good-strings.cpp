class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100005]; // Only depends on `length`

    int f(int length, int numzero, int numone) {
        if (length == 0) {
            return 1; // Base case: valid string formed
        }
        if (dp[length] != -1) return dp[length]; // Use cached result

        int count = 0;
        if (length >= numzero) {
            count = (count + f(length - numzero, numzero, numone)) % mod;
        }
        if (length >= numone) {
            count = (count + f(length - numone, numzero, numone)) % mod;
        }

        return dp[length] = count; // Cache the result
    }

    int countGoodStrings(int low, int high, int numzero, int numone) {
        memset(dp, -1, sizeof(dp)); // Initialize DP array
        int ans = 0;

        for (int i = low; i <= high; i++) {
            ans = (ans + f(i, numzero, numone)) % mod;
        }

        return ans;
    }
};
