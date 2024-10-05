#include <vector>
#include <string>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length())
            return false;

        std::vector<int> s1arr(26, 0);
        std::vector<int> s2arr(26, 0);

        // Count frequency of characters in s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++) {
            s1arr[s1[i] - 'a']++;
            s2arr[s2[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] == s2arr[i])
                count++;
        }

        // Sliding window over s2
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (count == 26)
                return true;

            int r = s2[i + s1.length()] - 'a'; // New character in the window
            int l = s2[i] - 'a';               // Old character out of the window

            // Update the new character count
            s2arr[r]++;
            if (s2arr[r] == s1arr[r]) {
                count++;
            } else if (s2arr[r] == s1arr[r] + 1) {
                count--;
            }

            // Update the old character count
            s2arr[l]--;
            if (s2arr[l] == s1arr[l]) {
                count++;
            } else if (s2arr[l] == s1arr[l] - 1) {
                count--;
            }
        }

        return count == 26;
    }
};