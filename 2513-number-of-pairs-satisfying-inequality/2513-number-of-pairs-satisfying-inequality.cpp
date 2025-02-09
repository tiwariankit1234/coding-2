#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            nums[i] = nums1[i] - nums2[i];
        }

        vector<int> values;
        long long to_ret = 0;

        for (int t : nums) {
            int pt = upper_bound(values.begin(), values.end(), t + diff) - values.begin();
            to_ret += pt;
            pt = lower_bound(values.begin(), values.end(), t) - values.begin();
            values.insert(values.begin() + pt, t);
        }

        return to_ret;
    }
};