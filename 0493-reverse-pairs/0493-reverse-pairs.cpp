class Solution {
public:
    int merge(vector<int>& a, vector<int>& b, vector<int>& nums) {
        int count = 0;
        int i = 0, j = 0, m = a.size();
        while (i < a.size() and j < b.size()) {
            if ((long long)a[i] > (long long)2 * b[j]) {
                count += (m - i);
                j++;
            } else {
                i++;
            }
        }
        int k = 0;
        i = 0, j = 0;
        while (i < a.size() and j < b.size()) {
            if (a[i] <= b[j]) {
                nums[k++] = a[i++];
            } else {
                nums[k++] = b[j++];
            }
        }
        while (i < a.size()) nums[k++] = a[i++];
while (j < b.size()) nums[k++] = b[j++];


        return count;
    }
    int mergesort(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int n = nums.size();
        int count = 0;
        vector<int> a(nums.begin(), nums.begin() + n / 2);
        vector<int> b(nums.begin() + (n / 2), nums.end());
        count += mergesort(a);
        count += mergesort(b);
        count += merge(a, b, nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums);
    }
};