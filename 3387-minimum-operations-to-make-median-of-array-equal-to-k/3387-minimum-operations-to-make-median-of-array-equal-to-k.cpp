#define ll long long

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll n=nums.size();

        ll ans=0;
        if(n%2){
             ll j=(n-1)/2;
             if(nums[j]<k){
            while(j<n and nums[j]<k){
                ans+=(abs)(nums[j]-k);
                j++;
            }
             } 
            else{
                while(j>=0 and nums[j]>k){
                    ans+=(abs)(nums[j]-k);
                    j--;
                }
            }
            return ans;  
        }
        else{
            ll j=(n-1)/2+1;
            if(nums[j]<k){
            while(j<n and nums[j]<k){
                ans+=(abs)(nums[j]-k);
                j++;
            }
             } 
            else{
                while(j>=0 and nums[j]>k){
                    ans+=(abs)(nums[j]-k);
                    j--;
                }
            }
            return ans;  
            
        }
        return 0;
    }
};