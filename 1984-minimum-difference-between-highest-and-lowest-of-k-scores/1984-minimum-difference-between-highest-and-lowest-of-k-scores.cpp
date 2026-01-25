class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1)return 0;
        sort(nums.begin(),nums.end());
        int idx=nums.size()-1,n=nums.size();
        int l=0,r=k-1;
        int ans=INT_MAX;
        while(r<(nums.size())){
            ans=min(ans,nums[r]-nums[l]);
            r++;
            l++;
        }
        return ans;
    }
};