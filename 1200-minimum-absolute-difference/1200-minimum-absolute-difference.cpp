class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        int mindiff=INT_MAX;
        for(int i=1;i<n;i++){
            mindiff=min(mindiff,nums[i]-nums[i-1]);
        }
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==mindiff){
                ans.push_back({nums[i-1],nums[i]});
            }
        }
        return ans;
    }
};