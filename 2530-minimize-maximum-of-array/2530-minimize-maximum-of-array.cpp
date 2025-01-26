#define ll long long 
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // Special case for 2 elements
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        // Binary search to minimize maximum
       ll left = 0, right = *max_element(nums.begin(), nums.end());
        ll ans = LLONG_MAX;
          vector<long long> v;
        for(auto x:nums){
            v.push_back(x);
        }
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            // cout << mid << endl;
            if (canReduceMax(v, mid)) {
                ans = mid;
                // cout << ans << endl;
                right = mid - 1; // Try to reduce the maximum value
            } else {
                left = mid + 1; // Increase the limit
            }
        }
        
        return ans;
    }
    
private:
    bool canReduceMax(vector<ll> nums, int maxLimit) {
        long long excess = 0; // To track the excess values
        
        // Redistribute values from right to left
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > maxLimit) {
                // Calculate excess and move it to the previous index
                excess = nums[i] - maxLimit;
                nums[i] -= excess;
                nums[i - 1] += excess;
            }
        }
        
        // Check if the max of the array is within the limit
        return *max_element(nums.begin(), nums.end()) <= maxLimit;
    }
};
