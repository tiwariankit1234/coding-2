#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       ll n=nums.size();
       unordered_map<ll,ll>mp;
      ll totalpair=((n-1)*n)/2,count=0;
       for(ll i=0;i<n;i++){
         if(mp.find((i-nums[i]))!=mp.end()){
            count+=mp[i-nums[i]];
         }
         mp[i-nums[i]]++;
       }
       return (totalpair)-count;
    }
};