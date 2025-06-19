class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, count = 1;
        while (j < n) {
            if (nums[j] - nums[i] <= k) {
                j++;
            } else {
                count++;
                i = j;
                j++;
            }
        }
        return count;
    }
};