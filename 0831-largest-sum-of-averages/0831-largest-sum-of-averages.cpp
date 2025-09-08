class Solution {
public:
    double dp[105][105];
    vector<double> prefix;

    double f(int idx, int k, vector<int>& nums) {
        int n = nums.size();
        if (idx == n) return 0.0; // valid to stop early
        if (k == 0) return -1e9;  // no partitions left but still elements remain

        if (dp[idx][k] >= 0) return dp[idx][k];

        double ans = 0.0;
        for (int j = idx; j < n; j++) {
            double avg = (prefix[j + 1] - prefix[idx]) / (j - idx + 1);
            ans = max(ans, avg + f(j + 1, k - 1, nums));
        }
        return dp[idx][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        // prefix sum
        prefix.assign(n + 1, 0.0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return f(0, k, nums);
    }
};
