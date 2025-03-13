class Solution {
public:
    void f(int idx, vector<int>& cookies, vector<int>& distribution, int k, int& ans) {
        // If we've considered all cookies
        if (idx == cookies.size()) {
            // Find the maximum cookies any child gets (the unfairness)
            int maxCookies = *max_element(distribution.begin(), distribution.end());
            ans = min(ans, maxCookies);
            return;
        }
        
        // Try giving the current cookie to each child
        for (int i = 0; i < k; i++) {
            distribution[i] += cookies[idx];
            f(idx + 1, cookies, distribution, k, ans);
            distribution[i] -= cookies[idx]; // Backtrack
            
            // Optimization: if this child has 0 cookies, break
            // This avoids duplicate assignments due to symmetry
            if (distribution[i] == 0) break;
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> distribution(k, 0); // Track cookies each child has
        f(0, cookies, distribution, k, ans);
        return ans;
    }
};