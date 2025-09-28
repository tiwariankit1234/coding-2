class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size(),sum=0,maxsum=INT_MIN;
        sort(nums.begin(),nums.end());
       
        int i=n-1;
        while(i>=2){
            if(nums[i]<(nums[i-1]+nums[i-2]))
           sum=nums[i]+nums[i-1]+nums[i-2];
           maxsum=max(maxsum,sum);
           i--;
        }
        return maxsum;
    }
};