class Solution {
public:
    int dp[2001][4001];// memo: dp[idx][curr]

    int f(int idx, int curr, vector<int>& nums) {
        int n = nums.size();
        if (idx == n) return 0;

        if (dp[idx][curr]!=-1) return dp[idx][curr];

        int maxscore = 0;

        if (nums[idx] > curr) {
       
            int newscore = curr + nums[idx];
            maxscore = max(maxscore, nums[idx] + f(idx + 1, newscore, nums));
          
        }

        // Skip current index
        maxscore = max(maxscore, f(idx + 1, curr, nums));

        return dp[idx][curr] = maxscore;
    }

    int maxTotalReward(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>s;
        for(auto it:nums)
        s.insert(it);
        for(auto it=s.begin();it!=s.end();it++)
       ans.push_back(*it);
        sort(ans.begin(), ans.end());
   
        memset(dp,-1,sizeof(dp));
       
        return f(0, 0, ans);
    }
};
