class Solution {
public:
    // Function to check if `searchWord` is a prefix of `word`
    bool check(string &searchWord, string &word) {
        int i = 0, j = 0;
        int searchLen = searchWord.size();
        int wordLen = word.size();

        // If `searchWord` is longer than `word`, it cannot be a prefix
        if (searchLen > wordLen) return false;

        // Compare characters one by one
        while (j < searchLen) {
            if (searchWord[j++] != word[i++]) return false;
        }

        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence); // To split the sentence into words
        vector<string> stringWords;
        string word;

        // Split the sentence into words and store in `stringWords`
        while (ss >> word) {
            stringWords.push_back(word);
        }

        // Debug print to check the split words
        for (auto it : stringWords)
            cout << it << " ";
        cout << endl;

        int n = stringWords.size();

        // Iterate through the words and check for prefix match
        for (int i = 0; i < n; i++) {
            if (check(searchWord, stringWords[i])) {
                return i + 1; // Return 1-based index of the matching word
            }
        }

        return -1; // No match found
    }
};
