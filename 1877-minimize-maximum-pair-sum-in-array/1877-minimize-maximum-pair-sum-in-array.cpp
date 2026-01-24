class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int sum=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<(n/2);i++){
            sum=max(sum,nums[i]+nums[n-i-1]);
        }
        return sum;
    }
};