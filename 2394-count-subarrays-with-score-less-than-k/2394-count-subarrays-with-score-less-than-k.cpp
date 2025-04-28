#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n=nums.size();
        ll count=0,sum=0,l=0,r=0,score=0;
        while(r<n){
            sum+=nums[r];
        
            while((sum*(r-l+1))>=k){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};