class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int minlen=n;
        unordered_map<int,int>mp;
        mp.insert({0,-1});
        long long currentsum=0;
        int target=0;
        for(int i=0;i<n;i++){
            currentsum=(currentsum+nums[i])%p;
        }
        target=currentsum%p;
        if(target==0)return 0;
        currentsum=0;
        for(int i=0;i<n;i++){
            currentsum=(currentsum%p+nums[i]%p)%p;
            int needed=(currentsum%p-target+p)%p;
            if(mp.find(needed)!=mp.end()){
                minlen=min(minlen,i-mp[needed]);
            }
            mp[currentsum%p]=i;
        }
        return minlen==n?-1:minlen;
    }
};