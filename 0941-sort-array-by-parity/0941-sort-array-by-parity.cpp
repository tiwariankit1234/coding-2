class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            if((nums[l]&1)==1 and (nums[r]&1)==0){
                swap(nums[l++],nums[r--]);
            }
            else if((nums[l]&1)==0){
                l++;
            }
            else{
                r--;
            }
        }
        return nums;
    }
};