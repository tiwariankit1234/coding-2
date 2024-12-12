// there is no need of doing operation just see problem 

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        int size=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int num=nums[i]+2*k;
            auto idx=upper_bound(nums.begin(),nums.end(),num);
            
            size=max(size,static_cast<int>(idx-nums.begin()-i));
        }
        return size;
    }
};