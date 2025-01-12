class Solution {
public:
    int dp[1002][1002];
    
    bool f(int i, int j, string &s) {
        if (i >= j) {
            return dp[i][j] = 1;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // If characters match, check inner substring
        if (s[i] == s[j]) {
            return dp[i][j] = f(i + 1, j - 1, s);
        }
        
        // If characters don't match, it's not a palindrome
        return dp[i][j] = 0;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        
        int maxlength = 1;  // Initialize with 1 since single character is palindrome
        int startidx = 0;
        
        // Check all possible substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (f(i, j, s) == 1 && (j - i + 1) > maxlength) {
                    maxlength = j - i + 1;
                    startidx = i;
                }
            }
        }
        
        return s.substr(startidx, maxlength);
    }
};