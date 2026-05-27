class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0, n = word.size();
      unordered_map<char,int>mp;
        int i = 0, j = 0;
        for (auto ch : word)
            mp[ch]++;

        for (int i = 0; i < 26; i++) {
            bool flag = true;
            char reqch = i + 'A';
            unordered_map<char, int> mp2;
            mp2 = mp;
            if (mp2.find(reqch) != mp2.end()) {
                for (char ch : word) {
                    if (ch == reqch) {
                        if (mp2.find(reqch+32)!=mp2.end() and mp2[reqch + 32] == 0) {
                            cout<<reqch<<endl;
                            count++;
                        }
                        break;
                    } else if (ch == reqch + 32) {
                        mp2[ch]--;
                    }
                }
            }
        }
        return count;
    }
};