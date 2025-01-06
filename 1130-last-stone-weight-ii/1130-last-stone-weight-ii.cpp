class Solution {
public:
    int totalsum;
    int dp[32][30002]; // Adjusted DP array size to fit the problem constraints

    void f(int idx, vector<int>& stones, int sum, int difference, int& maxdifference) {
        if (idx == stones.size()) {
            // Update maxdifference with the minimal positive difference
            if (difference >= 0) {
                maxdifference = min(maxdifference, difference);
            }
            return;
        }

        if (dp[idx][sum] != -1) return;

        // Calculate new sums and differences
        int newsum = sum + stones[idx];
        int newdifference = abs((2 * newsum) - totalsum);
        
        // Recursively explore the two possibilities
        f(idx + 1, stones, newsum, newdifference, maxdifference); // Include current stone
        f(idx + 1, stones, sum, difference, maxdifference);       // Exclude current stone
        
        // Store the result in DP to avoid redundant calculations
        dp[idx][sum] = maxdifference;
        return;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        totalsum = accumulate(stones.begin(), stones.end(), 0); // Calculate the total sum of stones

        // Initialize the DP array with -1
        memset(dp, -1, sizeof(dp));

        int maxdifference = INT_MAX; // Initialize maxdifference with the maximum possible value

        // Start the recursive function
        f(0, stones, 0, maxdifference, maxdifference);

        return maxdifference == INT_MAX ? 0 : maxdifference;
    }
};
