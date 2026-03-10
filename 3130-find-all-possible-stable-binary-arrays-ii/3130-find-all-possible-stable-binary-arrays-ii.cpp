class Solution {
public:
    int mod = 1e9 + 7;
    int limit;
    vector<vector<vector<long long>>> dp;

    long long f(int zero, int one, int previousbit) {
        if (zero < 0 || one < 0) return 0;

        // Base case: perfectly ran out of both
        if (zero == 0 && one == 0) return 1;

        // Base case: Only 0s left to place
        if (one == 0) {
            // If the last bit was 1, we are starting a fresh streak of 0s
            if (previousbit == 1 && zero <= limit) return 1;
            // If the last bit was 0, we are continuing an existing streak
            if (previousbit == 0 && zero <= limit - 1) return 1;
            return 0;
        }
        
        // Base case: Only 1s left to place
        if (zero == 0) {
            // If the last bit was 0, we are starting a fresh streak of 1s
            if (previousbit == 0 && one <= limit) return 1;
            // If the last bit was 1, we are continuing an existing streak
            if (previousbit == 1 && one <= limit - 1) return 1;
            return 0;
        }

        if (dp[zero][one][previousbit] != -1)
            return dp[zero][one][previousbit];

        long long count = 0;

        if (previousbit == 0) {
            // Extend with either 0 or 1
            count = (f(zero - 1, one, 0) + f(zero, one - 1, 1)) % mod;     

            // Subtract invalid branch: placing `limit` more 0s, then a capping 1
            if (zero - limit >= 0 && one - 1 >= 0) {
                count = (count - f(zero - limit, one - 1, 1) + mod) % mod;
            }
        } 
        else {
            // Extend with either 0 or 1
            count = (f(zero - 1, one, 0) + f(zero, one - 1, 1)) % mod;     

            // Subtract invalid branch: placing `limit` more 1s, then a capping 0
            if (one - limit >= 0 && zero - 1 >= 0) {
                count = (count - f(zero - 1, one - limit, 0) + mod) % mod;
            }
        }

        return dp[zero][one][previousbit] = count;
    }

    int numberOfStableArrays(int zero, int one, int lim) {
        limit = lim;
        
        dp = vector<vector<vector<long long>>>(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, -1))
        );

        long long count = 0;

        // Start the array by consuming the very first bit
        if (zero > 0) count = (count + f(zero - 1, one, 0)) % mod;
        if (one > 0)  count = (count + f(zero, one - 1, 1)) % mod;

        return count;
    }
};