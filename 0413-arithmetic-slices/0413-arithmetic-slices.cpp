class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int count=0,l=0,r=2;
        if(n<2)return 0;
        int curr=1;
           while(r<n){
           if(nums[r]-nums[r-1] ==(nums[r-1]-nums[r-2])){
            count+=curr;
             curr++;
           }
           else{
            curr=1;
           }
           r++;
        }
        return count;
    }
};