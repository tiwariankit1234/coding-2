class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int zerocount=0,maxlength=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)zerocount++;
            int onecount=(i+1)-zerocount;
            if(mp.find(onecount-zerocount)!=mp.end()){
                maxlength=max(maxlength,i-mp[onecount-zerocount]);
            }
           if(mp.find(onecount-zerocount)==mp.end())mp[onecount-zerocount]=i;
        }
        return maxlength;
    }
};