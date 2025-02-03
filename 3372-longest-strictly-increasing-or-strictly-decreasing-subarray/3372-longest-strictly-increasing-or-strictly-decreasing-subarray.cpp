class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
          int l=0,r=1,maxsize=1;
        while(r<n){
              if(nums[r]<=nums[r-1]){
                l=r;
              }
              maxsize=max(maxsize,(r-l+1));
              r++;
        }
          l=0,r=1;
         while(r<n){
              if(nums[r]>=nums[r-1]){
                l=r;
              }
              maxsize=max(maxsize,(r-l+1));
              r++;
        }

        return maxsize;
    }
};