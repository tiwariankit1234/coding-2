
#define ll long long 
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       ll n=nums.size();

       sort(nums.begin(),nums.end());

        unordered_set<ll>s;

        for(auto it:nums)
        s.insert(it);
         
         ll maxlength=-1;
        for(ll i=0;i<n;i++){
            ll num=nums[i];
            ll count=1;

            while(s.find(num*num)!=s.end()){
                count++;
                num=num*num;
            }
            maxlength=max(count,maxlength);
        }
        return (maxlength==1)?-1:maxlength;
    }
};