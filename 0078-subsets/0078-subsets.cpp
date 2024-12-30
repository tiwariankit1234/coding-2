class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>&v,int idx,vector<int>& nums){
        if(idx==nums.size())
        {
            ans.push_back(v);
            return;

        }
              v.push_back(nums[idx]);
           f(ans,v,idx+1,nums);
           v.pop_back();
        
       f(ans,v,idx+1,nums);

       

return ;
      }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
         vector<vector<int>>ans;
        f(ans,v,0,nums);
        return ans;
    }
};