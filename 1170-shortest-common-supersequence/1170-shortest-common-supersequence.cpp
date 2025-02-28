#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:

    int dp[1002][1002];

    string longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        memset(dp, 0, sizeof(dp));

        // Fill the dp table for LCS
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // Construct the SCS from the LCS
        string s;
        int i = 0, j = 0;
        
        while (i < m && j < n) {
            if (s1[i] == s2[j]) {
                s.push_back(s1[i]);
                i++;
                j++;
            } else if (dp[i + 1][j] > dp[i][j + 1]) {
                s.push_back(s1[i]);
                i++;
            } else {
                s.push_back(s2[j]);
                j++;
            }
        }

        // Add remaining characters from s1 or s2 (if any)
        while (i < m) {
            s.push_back(s1[i]);
            i++;
        }
        while (j < n) {
            s.push_back(s2[j]);
            j++;
        }

        // Output the constructed SCS
        cout << s << endl;

        return s;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        return longestCommonSubsequence(str1, str2);
    }
};
