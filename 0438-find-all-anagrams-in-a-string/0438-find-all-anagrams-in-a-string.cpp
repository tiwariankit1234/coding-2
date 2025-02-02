class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        if (n < k) return {};
        
        unordered_map<char, int> freq;
        for (char c : p) freq[c]++;
        
        int requiredMatches = freq.size();  // Number of unique characters in 'p'
        int matchCount = 0;
        vector<int> ans;
        
        for (int l = 0, r = 0; r < n; r++) {
            // Expand window
            if (--freq[s[r]] == 0) matchCount++;

            // Maintain window size
            if (r - l + 1 > k) {
                if (freq[s[l]] == 0) matchCount--;
                freq[s[l]]++;
                l++;
            }
            
            // If all characters match, store the index
            if (matchCount == requiredMatches) ans.push_back(l);
        }
        return ans;
    }
};
