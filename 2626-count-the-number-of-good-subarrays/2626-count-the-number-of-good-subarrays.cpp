#define ll long long 
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        unordered_map<int,int>mp;
      ll count=0,sum=0;
        while(r<n){
          if(mp.find(nums[r])!=mp.end()){
            count+=mp[nums[r]];
          }
              mp[nums[r]]++;
        //   cout<<l<<" "<<r<<" "<<count<<endl;
          while(count>=k){
          
            sum+=n-r;
            // cout<<sum<<" "<<nums[l]<<" "<<count<<" "<<nums[r]<<endl;
            mp[nums[l]]--;
           count=count-(mp[nums[l]]);
           l++;
          }
      
          r++; 
        }
        return sum;
    }
};