class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCount(32, 0); // count of set bits at each position
        int start = 0, val = 0;
        int ans = INT_MAX;

        for (int end = 0; end < n; end++) {
            // Add nums[end] to the OR
            for (int i = 0; i < 32; i++) {
                if (nums[end] & (1 << i)) {
                    if (bitCount[i] == 0) val |= (1 << i);
                    bitCount[i]++;
                }
            }

            // Shrink window while condition satisfied
            while (val >= k && start <= end) {
                ans = min(ans, end - start + 1);

                // Remove nums[start] from OR
                for (int i = 0; i < 32; i++) {
                    if (nums[start] & (1 << i)) {
                        bitCount[i]--;
                        if (bitCount[i] == 0) val &= ~(1 << i);
                    }
                }
                start++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
