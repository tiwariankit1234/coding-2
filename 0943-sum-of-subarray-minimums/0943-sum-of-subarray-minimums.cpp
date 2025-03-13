int mod=1e9+7;

// This is impossible to derive in interview. An easier way of looking at it is this:

// The number of subarrays with 3 in it will be anything that starts in [L..3] and ends in [3..R]. So we have [L..3] starting positions and [3..R] ending positions. In other words, we have d1 starting positions and d2 ending positions. So the total number of subarrays is just d1*d2.

// For example:
// in [9,7,8,3,4,6]
// we have 4 choices to start with (9,7,8,3)
// we have 3 choices to end with (3,4,6)

// So answer is just 4*3.
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < length; ++i) {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};