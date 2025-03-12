class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size(),pos=0,neg=0;
        int posidx=upper_bound(nums.begin(),nums.end(),0)-nums.begin();
         pos=n-posidx;
         int negidx=upper_bound(nums.begin(),nums.end(),-1)-1-nums.begin();
        //  if(negidx==-1)
        //  neg=0;
        //  else
         neg=negidx+1;

         return max(pos,neg);

    }
};