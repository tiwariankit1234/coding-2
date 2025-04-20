class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
          if(mp[nums[i]]==0){
            ans+=nums[i]+1;
          }
          
          mp[nums[i]]++;
          if(mp[nums[i]]>=nums[i]+1)
          mp[nums[i]]=0;
       }
       return ans;
    }
};