class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int water=0;

        while(i<j){
            if(nums[i]<=nums[j]){
                water=max(water,min(nums[i],nums[j])*(j-i));
                i++;
            }
            else{
                water=max(water,min(nums[i],nums[j])*(j-i));
                j--;
            }
        }
        return water;
    }
};