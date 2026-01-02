class Solution {
public:

int findDuplicate(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correctidx = nums[i] - 1;
        if (nums[i] != nums[correctidx]) {
            swap(nums[i], nums[correctidx]);
        } else {
            if (i != correctidx)
                return nums[i];
            i++;
        }
    }
    return -1;
}
};
