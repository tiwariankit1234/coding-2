class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ans.empty()||ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                auto it=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
               ans[it]=nums[i];
            }
        }
        return ans.size();
    }
};