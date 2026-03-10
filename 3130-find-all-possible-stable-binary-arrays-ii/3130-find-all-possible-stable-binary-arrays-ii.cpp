class Solution {
public:
    int mod = 1e9 + 7;
    int limit;
    vector<vector<vector<long long>>> dp;

    long long f(int zero, int one, int prev) {
        // Prunes any invalid branches naturally
        if (zero < 0 || one < 0) return 0;
        
        // Successfully placed all elements
        if (zero == 0 && one == 0) return 1;

        // Base case: Only 1s left to place
        if (zero == 0) {
            // If previous was 0, we start a fresh streak of 1s
            if (prev == 0 && one <= limit) return 1;
            // If previous was 1, we are continuing the current streak
            if (prev == 1 && one <= limit - 1) return 1;
            return 0;
        }
        
        // Base case: Only 0s left to place
        if (one == 0) {
            // If previous was 1, we start a fresh streak of 0s
            if (prev == 1 && zero <= limit) return 1;
            // If previous was 0, we are continuing the current streak
            if (prev == 0 && zero <= limit - 1) return 1;
            return 0;
        }

        if (dp[zero][one][prev] != -1) return dp[zero][one][prev];

        // Telescoping sum: explore placing a 0 and placing a 1
        long long count = (f(zero - 1, one, 0) + f(zero, one - 1, 1)) % mod;

        // Subtract the exact sequence that creates an invalid streak of (limit + 1)
        if (prev == 0) {
            count = (count - f(zero - limit, one - 1, 1) + mod) % mod;
        } else {
            count = (count - f(zero - 1, one - limit, 0) + mod) % mod;
        }

        return dp[zero][one][prev] = count;
    }

    int numberOfStableArrays(int zero, int one, int lim) {
        limit = lim;
        
        dp = vector<vector<vector<long long>>>(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, -1))
        );

        long long count = 0;
        
        // Start the array by placing the very first bit
        if (zero > 0) count = (count + f(zero - 1, one, 0)) % mod;
        if (one > 0)  count = (count + f(zero, one - 1, 1)) % mod;
        
        return count;
    }
};