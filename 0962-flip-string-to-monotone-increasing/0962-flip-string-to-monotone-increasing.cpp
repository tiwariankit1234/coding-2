class Solution {
public:
    int dp[100006][2];

    int f(int idx, char prevchar, string& s) {
        int n = s.size();
        if (idx == n) return 0;

        if (dp[idx][prevchar - '0'] != -1) return dp[idx][prevchar - '0'];

        int ans = 1e6;

        if (prevchar == '1') {
            // Can only continue with '1's
            if (s[idx] == '1') {
                ans = f(idx + 1, '1', s);
            } else {
                ans = 1 + f(idx + 1, '1', s); // flip 0 -> 1
            }
        } else {
            // prevchar == '0', two choices
            if (s[idx] == '0') {
                // Option 1: keep as '0'
                ans = f(idx + 1, '0', s);
                // Option 2: flip 0 -> 1
                ans = min(ans, 1 + f(idx + 1, '1', s));
            } else {
                // s[idx] == '1'
                // Option 1: keep as '1'
                ans = f(idx + 1, '1', s);
                // Option 2: flip 1 -> 0
                ans = min(ans, 1 + f(idx + 1, '0', s));
            }
        }

        return dp[idx][prevchar - '0'] = ans;
    }

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(0, '0', s); // Start assuming previous was '0'
    }
};
