class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int runningsum=0,maxsum=INT_MIN,minsum=INT_MAX;
        for(int i=0;i<n;i++){
            runningsum+=nums[i];
            maxsum=max(runningsum,maxsum);
            if(runningsum<0)runningsum=0;
        }
      
        runningsum=0;
        for(int i=0;i<n;i++){
            runningsum+=nums[i];
            minsum=min(runningsum,minsum);
            if(runningsum>0)runningsum=0;
        }
        return max(abs(minsum),abs(maxsum));
    }
};