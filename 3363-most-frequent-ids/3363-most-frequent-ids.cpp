#define ll long long
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        ll n=nums.size();
        vector<ll>ans(n);
        map<ll,ll>mp1,mp2;
        for(ll i=0;i<n;i++){
           ll num=mp1[nums[i]];
            mp1[nums[i]]+=freq[i];
            ll updatedfreq=mp1[nums[i]];
            mp2[updatedfreq]++;
            mp2[num]--;
            if(mp2[num]==0 ||mp2[num]==-1)mp2.erase(num);
            auto it=mp2.rbegin();
           
          
            if(mp2.size()==0){
                ans[i]=0;
                continue;
            }
            ans[i]=it->first;
        }
        return ans;

    }
};