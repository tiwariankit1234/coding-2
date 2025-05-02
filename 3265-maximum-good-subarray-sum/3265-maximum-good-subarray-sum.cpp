#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size();
        ll sum = 0, l = 0, r = 0, maxsum = LLONG_MIN;
        unordered_map<ll, ll> mp;
        vector<ll> prefixsum(n);
        prefixsum[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefixsum[i] = prefixsum[i - 1] + nums[i];

          

        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i] - k) != mp.end()) {
                int left = mp[nums[i] - k];
                if (left == 0 and (nums[i] - k) == nums[0]) {
                    maxsum = max(maxsum, (ll)prefixsum[i]);
                } else {
                    maxsum =
                        max(maxsum, (ll)(prefixsum[i] - prefixsum[left - 1]));
                }
            }
            if (mp.find(nums[i] + k) != mp.end()) {
                int left = mp[nums[i] + k];
                if (left == 0 and (nums[i] + k) == nums[0]) {
                    maxsum = max(maxsum, (ll)prefixsum[i]);
                } else {
                    maxsum =
                        max(maxsum, (ll)(prefixsum[i] - prefixsum[left - 1]));
                }
            }
            if (mp.find(nums[i]) != mp.end()){
                int index=mp[nums[i]];
                if(prefixsum[index]>prefixsum[i])
                 mp[nums[i]]=i;
                 else
                 mp[nums[i]]=index;
            }
            else{
                mp[nums[i]]=i;
            }
               
               
        }
        if(maxsum==LLONG_MIN)return 0;
        return maxsum;
    }
};