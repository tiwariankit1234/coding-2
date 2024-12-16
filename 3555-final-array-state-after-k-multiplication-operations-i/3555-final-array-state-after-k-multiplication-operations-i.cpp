#define ll long long 
#define mod 1000000007

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int modulo=1e9+7;
        int n=nums.size();
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        ll i=0;

        for(auto it:nums)
        pq.push({it,i++});
          
         ll minielement,idx;
        while(k--){
              auto[minielement,idx]=pq.top();
              pq.pop();
              nums[idx]=((((ll)minielement)%mod)*((multiplier%mod)))%mod;
               pq.push({nums[idx],idx});
        }
        return nums;
    }
};