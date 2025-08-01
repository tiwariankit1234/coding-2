class Solution {
public:
    // Function to check if the array is sorted in non-decreasing order
    bool issorted(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    }

    bool canSortArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> bitCount(n);

        // Calculate popcount for each element
        for (int i = 0; i < n; i++) {
            bitCount[i] = __builtin_popcount(arr[i]);
        }

        // Sort all subarrays with same popcount
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && bitCount[j] == bitCount[i]) {
                j++;
            }
            sort(arr.begin() + i, arr.begin() + j);
            i = j;
        }

        // Check if the entire array is sorted
        return issorted(arr);
    }
};
