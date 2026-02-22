#define ll long long
class Solution {
public:
     map<tuple<ll,ll,ll>,ll>mp;
       ll gcd(ll a,ll b){
            return b==0?a:gcd(b,a%b);
       }
    ll f(ll idx,ll numerator,ll denominator,ll k,vector<int>&nums){
        int n=nums.size();
        if(idx==n){
            if((numerator%denominator)==0){
                if((numerator==k*denominator))return 1;
            }
            return 0;
        }
         ll a=gcd(numerator,denominator);
        numerator/=a;
        denominator/=a;
        if(mp.find({idx,numerator,denominator})!=mp.end())return mp[{idx,numerator,denominator}];
        ll count=0;
        ll x=gcd(numerator,denominator);
        numerator/=x;
        denominator/=x;
        count+=f(idx+1,numerator,denominator,k,nums);
        // ll y=gcd(numerator*nums[idx],denominator);
        // ll newnumerator1=(numerator*nums[idx])/y;
        // ll newdenominator1=denominator/y;
        count+=f(idx+1,numerator*nums[idx],denominator,k,nums);
        count+=f(idx+1,numerator,denominator*nums[idx],k,nums);
        return mp[{idx,numerator,denominator}]=count;
    }
    int countSequences(vector<int>& nums, long long k) {
        ll n=nums.size(),numerator=1,denominator=1;
        return f(0,numerator,denominator,k,nums);
    }
};