
//https://leetcode.com/problems/palindrome-partitioning-ii/description/
// precomputation of pallindrome is required
class Solution {
public:
    // at max O(N2) calls to the functions
    bool isPalindrome(string& s, int l, int r, vector<vector<int>>& dp){
        if(l >= r) return true;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] == s[r]) return dp[l][r] = isPalindrome(s, l+1, r-1, dp);
        return dp[l][r] = false;
    }
    int n;
    int performMinCuts(string& s, int index, vector<int>& dp, vector<vector<int>>& pDp){
        if(index == n){
            return 0;
        }
        int minCuts = 100000;
        if(dp[index] != -1) return dp[index];
        // no need to partition, if substr is already palindrome
        if(isPalindrome(s, index, n-1, pDp)) return dp[index] = 0; 
        for(int i = index; i < n; i++){
            if(isPalindrome(s, index, i, pDp)){
                // try to cut from here
                minCuts = min(minCuts, 1 + performMinCuts(s, i+1, dp, pDp));
            }
        }
        return dp[index] = minCuts;
    }

    int minCut(string s) {
        n = s.size();
        vector<int> dp(n, -1); // dp for minCut problem
        vector<vector<int>> pDp(n, vector<int>(n, -1)); // dp for palindrome
        return performMinCuts(s, 0, dp, pDp);
    }
};