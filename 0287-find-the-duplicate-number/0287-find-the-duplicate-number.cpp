class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctidx=nums[i];
            if(nums[i]!=nums[correctidx-1]){
                swap(nums[i],nums[correctidx-1]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i])return nums[i];
        }
        return -1;
    }
};