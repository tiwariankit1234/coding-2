class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0); // size: [0 .. 2*limit+1]

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            // Everything starts as 2 moves
            diff[2] += 2;

            // Reduce to 1 move between [low, high]
            diff[low] -= 1;
            diff[high + 1] += 1;

            // Reduce to 0 moves at exact sum
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int res = INT_MAX, curr = 0;
        for (int i = 2; i <= 2 * limit; ++i) {
            curr += diff[i];
            res = min(res, curr);
        }

        return res;
    }
};
