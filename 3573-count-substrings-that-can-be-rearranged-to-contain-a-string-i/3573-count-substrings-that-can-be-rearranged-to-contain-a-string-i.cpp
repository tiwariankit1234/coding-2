#include <unordered_map>
#include <string>

class Solution {
public:
    // Check if mp1 contains all characters in mp2 with required frequency
    bool check(const std::unordered_map<char, int>& mp1, const std::unordered_map<char, int>& mp2) {
        for (const auto& it : mp2) {
            // Check if the character exists in mp1 and has at least the required count
            if (mp1.find(it.first) == mp1.end() || mp1.at(it.first) < it.second) {
                return false;
            }
        }
        return true;
    }

    long long validSubstringCount(std::string& word1, const std::string& word2) {
        int n = word1.size();
        int m = word2.size();

        std::unordered_map<char, int> mp1, mp2;

        // Build frequency map for word2
        for (char c : word2) {
            mp2[c]++;
        }

        long long count = 0;
        int i = 0;

        // Sliding window approach
        for (int j = 0; j < n; j++) {
            mp1[word1[j]]++;

            // Check if current window contains all characters of word2
            while (check(mp1, mp2)) {
                // Count all valid substrings starting from index i to j
                count += (n - j); // All substrings from i to j are valid
                mp1[word1[i]]--; // Remove the character at i from the window
                if (mp1[word1[i]] == 0) {
                    mp1.erase(word1[i]); // Remove it from map if its count is zero
                }
                i++; // Move the left end of the window forward
            }
        }
        
        return count;
    }
};
