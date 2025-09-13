class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1; // on day 1, one person knows the secret

        for (int i = 2; i <= n; i++) {
            for (int j = max(1, i - forget + 1); j <= i - delay; j++) {
                dp[i] = (dp[i] + dp[j]) % mod;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};
