class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        priority_queue<int> pq;
        int n=nums.size();
        long long ans=0;
        int mod = 1000*1000*1000+7;
        vector<int> cnt(n+1,0);
        for(auto &v : requests)
            cnt[v[0]]++, cnt[v[1]+1]--;
        for(int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
        for(int i=0; i<n; i++) pq.push(cnt[i]);
        sort(nums.rbegin(),nums.rend());
        int j=0;
        while(!pq.empty()) {
            ans = (ans+1LL*pq.top()*nums[j++] % mod) % mod;
            pq.pop();
        }
        return ans;
    }
};