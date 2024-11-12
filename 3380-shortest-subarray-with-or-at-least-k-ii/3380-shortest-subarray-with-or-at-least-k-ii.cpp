#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> bitcount = vector<int>(32, 0); // Initialize bitcount vector with 32 zeros

    void updatevector(int num, vector<int>& bitcount) {
        int count = 0;
        while (num > 0) {
            if (num % 2) {
                bitcount[count]++;
            }
            count++;
            num /= 2;
        }
    }

    void reupdatevector(int num, vector<int>& bitcount) {
        int count = 0;
        while (num > 0) {
            if (num % 2) {
                bitcount[count]--;
            }
            count++;
            num /= 2;
        }
    }

    int extractnumber(const vector<int>& bitcount) {
        int num = 0;
        for (int i = 0; i < 32; i++) {
            if (bitcount[i] > 0) { // Set bit i if bitcount[i] > 0
                num |= (1 << i);
            }
        }
        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0)return 1;
        int n = nums.size();
        int l = 0, r = 0, size = INT_MAX;
        int result = 0;

        while (r < n) {
            // Include nums[r] in the sliding window
            result |= nums[r];
            updatevector(nums[r], bitcount);

            // Shrink the window from the left while result >= k
            while (result >= k) {
                size = min(size, r - l + 1); // Update minimum size
                reupdatevector(nums[l], bitcount); // Remove nums[l] from bitcount
                l++; // Move left pointer
                result = extractnumber(bitcount); // Recalculate the OR result from bitcount
            }

            r++; // Move right pointer
        }

        return (size == INT_MAX) ? -1 : size; // Return -1 if no subarray found
    }
};