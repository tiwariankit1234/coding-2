class Solution {
public:
    long long maximumHappinessSum(vector<int>&nums, int k) {
        long long totalhap=0,count=0;
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        while(j>=0 and k>0){
            if((nums[j]-count)>=0)
          totalhap=totalhap+nums[j]-count;
          else{
            break;
          }
          count++;
          j--;
          k--;
        }
        return totalhap;
    }
};