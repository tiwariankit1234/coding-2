class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1,count=0;
        sort(nums.begin(),nums.end());
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum<target){
                count+=r-l;
                l++;
            }
            else{
                r--;
            }
        }
        return count;
    }
};