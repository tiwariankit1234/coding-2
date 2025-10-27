class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int oddcount=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1)oddcount++;
            count+=mp[oddcount-k];
            mp[oddcount]++;
        }
        return count;
    }
};