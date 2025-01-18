#define ll long long int
class Solution {
public:
    long long maximumOr(vector<int>& nums, ll k) {
        ll n=nums.size();
        vector<ll>prefix(n,0),suffix(n,0);
        prefix[0]=0;
        suffix[n-1]=0;
        for(ll i=1;i<n;i++){
            prefix[i]=prefix[i-1]|nums[i-1];
        }
        
        for(ll i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]|nums[i+1];
        }
         ll ans=0;
         for(ll i=0;i<(n);i++){
             ans=max(ans,prefix[i]|nums[i]*(1LL << k)|suffix[i]);
         }
      
         return ans;


    }
};