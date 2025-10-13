#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;

    // Step 1: Find pivot (smallest element index)
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1; // pivot in right half
        } else {
            right = mid; // pivot in left half (including mid)
        }
    }
    cout<<nums[left]<<endl;

    int pivot = left;
    cout<<left<<endl;

    // Step 2: Binary search with pivot offset
    left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout<<nums[mid]<<endl;
        int realMid = (mid + pivot) % n;
        cout<<realMid<<" "<<nums[realMid]<<endl;

        if (nums[realMid] == target)
            return realMid;
        if (nums[realMid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // target not found
}
};


