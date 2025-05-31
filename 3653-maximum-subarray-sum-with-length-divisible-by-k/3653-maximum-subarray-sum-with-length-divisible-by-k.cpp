#define ll long long 
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll n=nums.size(),sum=0,maxsum=LLONG_MIN;
        unordered_map<ll,ll>mp;
        mp[0]=0;
        for(int j=1;j<k;j++)
        mp[j]=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if((i+1-k)>=0){
                if(mp.find((i+1-k)%k)!=mp.end())
               maxsum=max(maxsum,sum-mp[(i+1-k)%k]);
            }
            mp[(i+1)%k]=min(sum,mp[(i+1)%k]);
            
          
        }
        return maxsum;
    }
};