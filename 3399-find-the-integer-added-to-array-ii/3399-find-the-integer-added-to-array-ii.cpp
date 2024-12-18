class Solution {
public:
    // Function to calculate the shift and check if it's valid
    int calculateShift(vector<int>& arr, vector<int>& nums2) {
        int n = arr.size();
        int m = nums2.size();
        if (n != m) return 8000; // Arrays must have the same size after removing elements
        
        // Calculate the shift using sorted arrays
        int shift = nums2[0] - arr[0];
        
        // Verify if applying this shift makes the arrays identical
        for (int i = 0; i < n; i++) {
            if (arr[i] + shift != nums2[i]) {
                return 8000; // Invalid shift
            }
        }
        return shift;
    }

    // Main function to find the minimum shift
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = 8000;

        // Sort the arrays for easier comparison
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Iterate over all subsets of nums1, removing up to 2 elements
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) { // Use j == n to skip only 1 element
                vector<int> remainingNums1;

                // Collect remaining elements excluding nums1[i] and nums1[j]
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        remainingNums1.push_back(nums1[k]);
                    }
                }

                // Calculate the shift and update the answer
                int shift = calculateShift(remainingNums1, nums2);
                if (shift != 8000) {
                    ans = min(ans, shift);
                }
            }
        }

        return (ans == 8000 ? -1 : ans); // Return -1 if no valid result is found
    }
};
