#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll, vector<ll>> mp;
        unordered_set<int> s,ultset;
        for (ll i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }


        vector<ll> ans(n, 0);
         for(auto m:mp) {
            int num=m.first;
            auto temp = mp[num];
            
          
            ll totalsum = 0;
            for (auto it : temp)
                totalsum += it;

            ll k = temp.size();
            ll sum = 0, leftsum = 0, rightsum = 0;
            for (ll j = 0; j < k; j++) {
                leftsum = 0, rightsum = 0;
                if (j != 0) {
                    leftsum = abs((j)*temp[j] - sum);
                }
                sum += temp[j];
                if (j != (k - 1))
                    rightsum = abs((k - (j + 1)) * temp[j] - (totalsum - sum));

                ans[temp[j]] = leftsum + rightsum;
            }
            
        }
        return ans;
    }
};