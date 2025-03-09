class Solution {
public:

void f(vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums,vector<bool>&used){
     int n=nums.size();
     if(temp.size()==nums.size()){
        ans.push_back(temp);
        return ;
     }
      
    for(int i=0;i<n;i++){
        if(  used[i]==true || i>0 and  nums[i]==nums[i-1] and used[i-1]==false )continue;
       
        used[i]=true;
        temp.push_back(nums[i]);
        f(temp,ans,nums,used);
        temp.pop_back();
        used[i]=false;
    }
    return;
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>>ans;
     vector<int>temp;
     vector<bool>used(nums.size(),false);
     sort(nums.begin(),nums.end());
      f(temp,ans,nums,used);
      return ans;
    }
};