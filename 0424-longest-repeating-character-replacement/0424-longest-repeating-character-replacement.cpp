class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0, r = 0, maxfrequency = 0, len = 0;
        
        while (r < n) {
            mp[s[r]]++;
            maxfrequency = max(maxfrequency, mp[s[r]]);
            
            // If window size - maxfrequency > k, shrink the window
            while ((r - l + 1) - maxfrequency > k) {
                mp[s[l]]--;
                l++;
            }
            
            // Update the maximum length found
            len = max(len, r - l + 1);
            r++;
        }
        
        return len;
    }
};
