class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr = nums;

        int n = nums.size();
        int counthills = 0, countvalleys = 0,left=nums[0];
        // track karo ki continuous window me kabhi answer nahi ayyega
        // toh hame unique element kab pakad sakte hain jab starting window ke left me unequal element mile 
        for (int i = 1; i < (n - 1); i++) {
            if (nums[i] != nums[i + 1]) {
                if (left < nums[i] and nums[i] > nums[i + 1]) {
                    counthills++;
                } else if (left > nums[i] and nums[i] < nums[i + 1]) {
                    counthills++;
                }
                left=nums[i];
            }
        }
        return counthills;
    }
};