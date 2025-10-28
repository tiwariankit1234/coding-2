class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0,count=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            count+=mp[sum-goal];
            mp[sum]++;
        }
        return count;
    }
};