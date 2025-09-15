class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),misiixor=0;
        for(int i=1;i<=n;i++){
           misiixor=misiixor^i;
        }
        for(int i=0;i<n;i++){
           misiixor=misiixor^nums[i];
        }
        return misiixor;
    }
};