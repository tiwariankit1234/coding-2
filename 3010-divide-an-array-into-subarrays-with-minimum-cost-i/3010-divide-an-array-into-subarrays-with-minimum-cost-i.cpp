class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               for(int k=j+1;k<n;k++){
                ans=min(ans,nums[0]+nums[j]+nums[k]);
               }
            }
        }
        return ans;
    }
};