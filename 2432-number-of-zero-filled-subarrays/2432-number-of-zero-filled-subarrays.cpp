#define ll long long 
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll n=nums.size(),l=0,r=0,count=0;
        while(r<n){
            if(nums[r]==0){
                count+=r-l+1;
            }
            else{
                l=r+1;
            }
            r++;
        }
        return count;
    }
};