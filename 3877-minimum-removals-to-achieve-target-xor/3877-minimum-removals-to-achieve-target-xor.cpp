class Solution {
public:
unordered_map<string,int>mp;
 int f(int idx,int currentxor,vector<int>&nums,int target){
    int n=nums.size();
    if(idx==n and currentxor!=target)return INT_MIN;
    if(idx==n and currentxor==target)return 0;
    int take=0,notake=0;
    string key=to_string(idx)+" "+to_string(currentxor);
    if(mp.find(key)!=mp.end())return mp[key];
    if(currentxor==target){
        int m=0;
        m=max(m,1+f(idx+1,currentxor^nums[idx],nums,target));
        m=max(m,f(idx+1,currentxor,nums,target));
        return mp[key]=m;
    }
    
    else{
         take=1+f(idx+1,currentxor^nums[idx],nums,target);
         notake=f(idx+1,currentxor,nums,target);
    }
    return mp[key]=max(take,notake);
 }
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        mp.clear();
        long long x=f(0,0,nums,target);
        if(x<0)return -1;
        return n-f(0,0,nums,target);
    }
};