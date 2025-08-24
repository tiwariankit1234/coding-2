class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(), count=0,maxsize=0,l=0,r=0;
          while(r<n){
            if(nums[r]==0)count++;
              
              while(l<n and count>=2){
                if(nums[l]==0)count--;
                l++;
              }
            if(count==1 ||count==0){
                maxsize=max(maxsize,r-l);
            }
            r++;
          }
          return maxsize;
    }
};