				// \U0001f609\U0001f609\U0001f609\U0001f609Please upvote if it helps \U0001f609\U0001f609\U0001f609\U0001f609
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        int i=0;
        while(i<nums.size())
        {
            int correctidx=nums[i];
            if(nums[correctidx]==nums[i])return nums[i];
            else swap(nums[i],nums[correctidx]);
        }
        return 1000;

        
    }
	// for github repository link go to my profile.
};