#define ll long long

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        ll ans=0,csum=0;
        unordered_map<int,int>mp;
        // initial condition
        while(j < nums.size())
        {
            csum += nums[j];
             mp[nums[j]]++;
            if((j-i+1)==k ){
                if(mp.size()==k){
                ans=max(csum,ans);
                }
                csum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            j++;
    }
    return ans;
    }
};