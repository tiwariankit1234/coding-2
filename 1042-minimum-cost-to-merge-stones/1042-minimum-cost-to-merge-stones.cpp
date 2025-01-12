class Solution {
public:
    vector<vector<int>> dp;       // DP table
    vector<int> prefixSum;        // Prefix sum array
    
    // Helper to get the sum of stones from index `l` to `r`
    int getSum(int l, int r) {
        return prefixSum[r + 1] - prefixSum[l];
    }
    
    // Recursive function to calculate the minimum cost to merge stones from index `i` to `j`
    int solve(int i, int j, int k, vector<int>& stones) {
        if (i == j) return 0;  // Base case: single pile
        
        if (dp[i][j] != -1) return dp[i][j]; // Use memoized result if available
        
        int result = INT_MAX;
        
        // Try merging all valid groups of size `k`
        for (int mid = i; mid < j; mid += k - 1) {
            int cost = solve(i, mid, k, stones) + solve(mid + 1, j, k, stones);
            result = min(result, cost);
        }
        
        // If the entire range can be merged into one pile, add the merging cost
        if ((j - i) % (k - 1) == 0) {
            result += getSum(i, j);
        }
        
        return dp[i][j] = result; // Memoize the result
    }
    
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        
        // Check if merging is possible
        if ((n - 1) % (k - 1) != 0) return -1;
        
        // Initialize DP table
        dp.resize(n, vector<int>(n, -1));
        
        // Compute prefix sums
        prefixSum.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }
        
        // Solve the problem for the entire range
        return solve(0, n - 1, k, stones);
    }
};
