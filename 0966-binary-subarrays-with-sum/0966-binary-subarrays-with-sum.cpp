class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int count=0,n=nums.size(),prefixsum=0;
        for(int i=0;i<n;i++){
          prefixsum+=nums[i];
          if(prefixsum==goal)count++;
          if(mp.find(prefixsum-goal)!=mp.end()){
            count+=mp[prefixsum-goal];
          }
          mp[prefixsum]++;
        }
        return count;
    }
};