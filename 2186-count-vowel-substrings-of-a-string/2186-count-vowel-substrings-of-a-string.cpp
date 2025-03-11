class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    // Helper function to count substrings with at most k different vowels
    int atMostKVowels(string& word, int k) {
        int n = word.size();
        int left = 0;
        int result = 0;
        unordered_map<char, int> vowelCount;
        
        for (int right = 0; right < n; right++) {
            // If not a vowel, reset window
            if (!isVowel(word[right])) {
                vowelCount.clear();
                left = right + 1;
                continue;
            }
            
            // Add current vowel to map
            vowelCount[word[right]]++;
            
            // Shrink window while we have more than k different vowels
            while (vowelCount.size() > k) {
                vowelCount[word[left]]--;
                if (vowelCount[word[left]] == 0) {
                    vowelCount.erase(word[left]);
                }
                left++;
            }
            
            // Add count of valid substrings ending at right
            result += right - left + 1;
        }
        
        return result;
    }
    
    int countVowelSubstrings(string word) {
        // Count substrings with exactly 5 different vowels
        // = (substrings with at most 5 different vowels) - (substrings with at most 4 different vowels)
        return atMostKVowels(word, 5) - atMostKVowels(word, 4);
    }
};