#define ll long long


class Solution {
public:

 bool possible(vector<int>& candies,ll k,ll mid){
    ll operations=0;
    ll n=candies.size();
    for(ll i=0;i<n;i++){
        operations+=((candies[i])/mid);
    }
    return (operations)>=k;
 }

    ll maximumCandies(vector<int>& candies, long long k) {
        // sort(candies.begin(),candies.end());
        ll low=1,high=1e9;
        ll ans=0;
        while(low<=high){
            ll mid=(low+high)/2;
            if(possible(candies,k,mid)){
                 ans=mid;
                low=mid+1;
              
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};