class Solution {
public:

int f(int idx,map<int,int>&mp,int prevans,vector<int>& nums){
    if(idx==nums.size()){
        return 0;
    }
   //
    int ans=nums[idx]|prevans;
    
    mp[ans]++;

    f(idx+1,mp,ans,nums);
   

    f(idx+1,mp,prevans,nums);

    return 0;



}

    int countMaxOrSubsets(vector<int>& nums) {
       int n=nums.size();

       map<int,int>mp;

     f(0,mp,0,nums);
     int start=0;
     for(auto it:mp){
       start=max(start,it.first);
     }

     return mp[start];
        
    }
};