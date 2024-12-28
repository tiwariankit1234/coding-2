class Solution {
public:

    int f(vector<int>& nums,int k){
        if(k<0)return 0;
           int n=nums.size();
        int l=0,r=0;
        int count=0,sum=0;
        unordered_map<int,int>mp;
        while(r<n){
           mp[nums[r]]++;
          while(mp.size()>k){
             mp[nums[l]]--;
             if(mp[nums[l]]==0)mp.erase(nums[l]);
            l++;
          }
          count+=(r-l+1);
          r++;
        }
        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};