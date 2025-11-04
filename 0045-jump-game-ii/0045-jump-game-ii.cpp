class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,farthest=0,jumps=0;
        while(r<(n-1)){
            for(int index=l;index<=r;index++){
                farthest=max(farthest,nums[index]+index);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
         return jumps;
    }
};