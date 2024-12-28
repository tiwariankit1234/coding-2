class Solution {
public:
    
    int f(vector<int>& nums,int k){
        if(k<0)return 0;
           int n=nums.size();
        int l=0,r=0;
        int count=0,sum=0;
        while(r<n){
          sum+=nums[r];
          while(sum>k){
            sum-=nums[l];
            l++;
          }
          count+=(r-l+1);
          r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count1=f(nums,goal);
        int count2=f(nums,goal-1);
        return count1-count2;
    }
};