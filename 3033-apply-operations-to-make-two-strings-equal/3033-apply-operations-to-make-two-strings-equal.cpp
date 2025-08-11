#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501];
    int diffIdx[501];
    int sz;

    int dfs(int i, int x) {
        if (i + 1 >= sz)
            return (i % 2) * x;

        if (dp[i] == 0) {
            dp[i] = min(
                dfs(i + 1, x) + x,  // Directly fix one mismatch
                dfs(i + 2, x) + (diffIdx[i + 1] - diffIdx[i])*2  // Pair fix
            );
        }
        return dp[i];
    }

    int minOperations(string s1, string s2, int x) {
        sz = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < (int)s1.size(); ++i) {
            if (s1[i] != s2[i])
                diffIdx[sz++] = i;
        }

        if (sz % 2) return -1; // Odd number of mismatches is impossible
        return dfs(0, x)/2;
    }
};