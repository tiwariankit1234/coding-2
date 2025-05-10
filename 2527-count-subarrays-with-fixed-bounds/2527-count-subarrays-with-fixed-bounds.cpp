#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        ll l=0,r=0,n=nums.size(),mini=-1,maxi=-1,count=0;
        bool validsubarray=false;
        while(r<n){
            if(nums[r]<mink || nums[r]>maxk)
            l=r+1;
            if(nums[r]==mink)
             mini=r;
             if(nums[r]==maxk)
             maxi=r;

             if(l<=maxi and maxi<=r and l<=mini and mini<=r  )
             count+=min(maxi,mini)-l+1;


            r++;
        }
        return count;
    }
};