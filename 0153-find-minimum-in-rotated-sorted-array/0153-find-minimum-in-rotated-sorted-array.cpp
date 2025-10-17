//Hey @Prathmesh Nikam! It's simple only man: If you are moving your pointers by mid + 1 or mid - 1 idx then you must use left <= right

// Otherwise, you must use left < right if you are moving your pointers by mid idx only.

// Hope that helps! try it out and see the magic :)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int low=0,high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[high];
    }
};