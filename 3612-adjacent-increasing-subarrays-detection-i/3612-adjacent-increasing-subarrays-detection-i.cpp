class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=1;
        int inc=1,previnc=1;
        while(r<n){
            if(nums[r]>nums[r-1]){
                inc++;
            }
            else{
                previnc=inc;
                inc=1;
            }
            if(inc>=2*k || previnc>=k and inc>=k)return true;
            r++;
        }
        return false;
    }
};