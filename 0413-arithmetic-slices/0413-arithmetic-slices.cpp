class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int curr=1;
        for(int i=2;i<n;i++){
           if(nums[i]-nums[i-1] ==(nums[i-1]-nums[i-2])){
            count+=curr;
             curr++;
           }
           else{
            curr=1;
           }
        }
        return count;
    }
};