#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n=nums.size();
        ll count=0,sum=0,l=0,r=0,score=0;
        ll totalsubarray=(n)*(n+1)/2;
        while(r<n){
            sum+=nums[r];
        
           while(sum*(r-l+1)>=k){
            count+=n-r;
            sum-=nums[l];
            l++;
           }
         
           r++;
        }
        return totalsubarray-count;
    }
};