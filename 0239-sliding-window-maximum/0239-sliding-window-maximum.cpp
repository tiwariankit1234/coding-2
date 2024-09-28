#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; // To store the result
        int n = nums.size();

        // Edge case: if nums is empty or k is 0
        if (n == 0 || k == 0) return ans;

        // Deque to store indices of elements in the current window
        deque<int> dq;

        // Process the first k elements
        for (int i = 0; i < k; i++) {
            // Remove indices that are out of this window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back(); 
            }
            dq.push_back(i); // Add current index to the deque
        }

        // The front of the deque is the largest element for the first window
        ans.push_back(nums[dq.front()]);

        // Process the remaining elements
        for (int j = k; j < n; j++) {
            // Remove indices that are out of this window
            while (!dq.empty() && dq.front() <= j - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[j] >= nums[dq.back()]) {
                dq.pop_back(); 
            }

            dq.push_back(j); // Add current index to the deque
            
            // The front of the deque is the largest element for the current window
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};