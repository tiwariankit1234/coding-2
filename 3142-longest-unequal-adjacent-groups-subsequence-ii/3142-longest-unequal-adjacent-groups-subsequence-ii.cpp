class Solution {
public:
    bool isValid(string& s, string& t) {
        if (s.size() != t.size())
            return false;

        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                count++;
            }
        }

        if (count == 1)
            return true;
        return false;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        int dp[1001];

        fill(dp, dp + 1001, 1);

        vector<vector<string>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i].push_back(words[i]);
            for (int j = 0; j < i; j++) {
                
                if (groups[i] != groups[j] and isValid(words[i], words[j])) {
                    if (dp[j] + 1 > (dp[i])) {
                        dp[i] = dp[j] + 1;
                        ans[i] = ans[j];
                        ans[i].push_back(words[i]);

                        
                    }
                }
            }
        }
    

   

int maxi = 0, idx = 0;
for (int i = 0; i < ans.size(); i++) {
    if (ans[i].size() > maxi) {
        maxi = ans[i].size();
        idx = i;
    }
}
return ans[idx];
}
};
