class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<pair<char, int>, int> mp;  // Map to store character and count of consecutive occurrences

        for (int i = 0; i < n; i++) {
            char currentchar = s[i];  // Current character
            int count = 0;  // To count consecutive occurrences of the current character

            // Iterate through the substring starting at index i
            for (int j = i; j < n; j++) {
                if (j > i && s[j] != s[j - 1]) {
                    break;  // Break if the current character is not the same as the previous one
                }
                
                // Increment count for the current character
                count++;
                
                // Store the (current character, count) pair in the map
                mp[{currentchar, count}]++;
            }
        }

        // Find the maximum length where the count of occurrences is >= 3
        int len = -1;  // Initialize to -1 to handle edge cases where no such substring exists
        for (auto& it : mp) {
            if (it.second >= 3) {  // If the substring appears at least 3 times
                len = max(len, it.first.second);  // Get the maximum length
            }
        }

        return len;  // Return the result
    }
};
   