class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxReach(n); // Initialize with size n
        int end=0;
        // Precompute the maxReach for each starting index
        for (int start = 0; start < n; ++start) {
             end = max(start,end);
            while (end < n - 1 && (nums[end] % 2) != (nums[end + 1] % 2)) {
                ++end;
            }
            maxReach[start] = end;
        }

        // Process each query
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int start = queries[i][0];
            int end = queries[i][1];
            ans[i] = (end <= maxReach[start]);
        }

        return ans;
    }
};
