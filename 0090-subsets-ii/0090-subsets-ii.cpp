class Solution {
public:
void f(int idx,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums,vector<bool>&used){
     int n=nums.size();
     ans.push_back(temp);
    for(int i=idx;i<n;i++){
        if(i>0 and nums[i]==nums[i-1] and used[i-1]==false)continue;
        used[i]=true;
        temp.push_back(nums[i]);
        f(i+1,temp,ans,nums,used);
        temp.pop_back();
        used[i]=false;
    }
    return;
}
    vector<vector<int>> subsetsWithDup(vector<int>&nums) {
     vector<vector<int>>ans;
     vector<int>temp;
     vector<bool>used(nums.size(),false);
     sort(nums.begin(),nums.end());
      f(0,temp,ans,nums,used);
      return ans;
    }
};