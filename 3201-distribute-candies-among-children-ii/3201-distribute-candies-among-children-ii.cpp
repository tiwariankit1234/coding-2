#define ll long long 

class Solution {
public:
    long long distributeCandies(ll n, ll limit) {
        ll count = 0;
        for (ll x = 0; x <= std::min(n, limit); x++) {
            ll sum = n - x;
           ll l=min(sum, limit);
           ll r=max(0LL, sum - limit);
           if(l>=r)
           count+=l-r+1; 
    
        }
        return count;
    }
};
