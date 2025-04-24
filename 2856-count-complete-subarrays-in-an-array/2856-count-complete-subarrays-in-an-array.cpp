class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,count=0;
        unordered_set<int>s;
        for(auto it:nums)
        s.insert(it);
        unordered_map<int,int>mp;
        int totalsize=s.size();
        while(r<n){
          mp[nums[r]]++;
          while(mp.size()==totalsize and l<n){
            count+=(n-r);
            mp[nums[l]]--;
            if(mp[nums[l]]==0)mp.erase(nums[l]);
            l++;
          }
          r++;
        }
        return count;
    }
};