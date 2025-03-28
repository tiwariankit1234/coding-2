//https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        int count=0;
        // set<pair<int,int>>s;
         unordered_map<int,int>mp;
        //  for(int i=0;i<n;i++){
        //     if(mp.find(nums[i]-k)!=mp.end()){
        //         s.insert({nums[i],nums[i]-k});
        //     }
        //     mp[nums[i]]++;
        //  }
        for(int i:nums){
            mp[i]++;
        }
        for(auto x:mp){
            
          if(k==0){
               if(mp[x.first]>=2) 
               count++; 
            }
           else if(mp.find(x.first+k)!=mp.end())
            count++;
        }
         return count;
    }
};