class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+5000, 1));

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= i - 1; j++) {
                int difference = nums[i] - nums[j] + 500;
                if (dp[j][difference] + 1 > dp[i][difference]) {
                    dp[i][difference] = 1 + dp[j][difference];
                    ans = max(ans, dp[i][difference]);
                }
            }
        }

        return ans;
    }
};