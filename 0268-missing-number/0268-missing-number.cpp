class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), i = 0;
        while (i < n) {
            int correctidx = nums[i];
            if (correctidx == n)
                i++;
            else if (nums[i] != nums[correctidx]) {
                swap(nums[i], nums[correctidx]);
            } else {
                i++;
            }
        }
        i = 0;

        cout << endl;
        for (i = 0; i < n; i++) {
            if (i != nums[i])
                return i;
        }
        return i;
    }
};