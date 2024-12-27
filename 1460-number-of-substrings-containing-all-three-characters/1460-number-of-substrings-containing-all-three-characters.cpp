class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0, count = 0;
        unordered_map<char, int> mp;

        // Sliding window to find valid substrings
        while (r < n) {
            mp[s[r]]++;  // Add the character at the right pointer
            while (mp.size() == 3) {  // When all three characters are in the window
                count += (n - r);  // All substrings starting with 'l' to 'r' are valid
                mp[s[l]]--;  // Shrink the window from the left
                if (mp[s[l]] == 0) mp.erase(s[l]);  // Remove character count if it becomes 0
                l++;  // Move the left pointer
            }
            r++;  // Move the right pointer
        }

        return count;
    }
};
