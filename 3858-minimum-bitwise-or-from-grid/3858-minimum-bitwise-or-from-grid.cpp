class Solution {
    int best = INT_MAX;

    int solve(int i, int curr, vector<vector<int>>& grid, unordered_map<long long, int>& memo) {
        // Pruning: OR is monotonic, cannot decrease further
        if (curr >= best) return INT_MAX;

        // Base case: all rows processed
        if (i == grid.size()) {
            best = min(best, curr);
            return curr;
        }

        // Memoization : Encode state using long long
        long long key = ((long long)i << 32) | curr;
        if (memo.count(key)) return memo[key];


        // Main Logic : Try all values in current row
        int ans = INT_MAX;
        for (int val : grid[i]) {
            int next = curr | val;
            ans = min(ans, solve(i + 1, next, grid, memo));
        }

        return memo[key] = ans;
    }

public:
    int minimumOR(vector<vector<int>>& grid) {
        unordered_map<long long, int> memo;
        return solve(0, 0, grid, memo);
    }
};