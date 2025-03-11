//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11
// aaabc
// is testcase me l a par aayega aur r c par tab hame a se start hone wali saari strings calculate karni padegi and then window shrink karna padega
//kyounk expand jab tak window valid na ho
// shrink jab tak karo string unvalid na ho jaye

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
