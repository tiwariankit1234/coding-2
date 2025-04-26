#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n=nums.size();
       ll l=0,r=0,maxelement=*max_element(nums.begin(),nums.end()),cnt=0;
        ll total=0;
        while(r<n){
            if(nums[r]==maxelement)
             cnt++;
               while(cnt==k){
                   total+=n-r;
                   if(nums[l]==maxelement)cnt--;
                   l++;
               }
             r++;
        }
        return total;
    }
};