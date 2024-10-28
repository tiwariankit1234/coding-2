
#define ll long long 
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       ll n=nums.size();

    

        unordered_set<ll>s(nums.begin(),nums.end());

       
         
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