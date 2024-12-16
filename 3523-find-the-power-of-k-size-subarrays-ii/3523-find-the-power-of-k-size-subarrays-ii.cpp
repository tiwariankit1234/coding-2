class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq; // to track the current sliding window

        for (int i = 0; i < n; ++i) {
            // Add current number to deque
            if (dq.empty() || nums[i] == dq.back() + 1) {
                dq.push_back(nums[i]);
            } else {
                // Clear deque and start fresh if sequence breaks
                dq.clear();
                dq.push_back(nums[i]);
            }

            // Start processing the window once size reaches k
            if (i >= k - 1) {
                // Check if deque contains k elements (indicating consecutive sequence)
                if (dq.size() == k) {
                    ans.push_back(dq.back()); // Add the maximum in the current window
                } else {
                    ans.push_back(-1); // Sequence is not valid
                }

                // Remove the oldest element in the sliding window
                if (!dq.empty() && dq.front() == nums[i - k + 1]) {
                    dq.pop_front();
                }
            }
        }

        return ans;
    }
};
