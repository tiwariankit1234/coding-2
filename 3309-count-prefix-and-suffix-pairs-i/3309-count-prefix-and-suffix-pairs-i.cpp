class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        ios::sync_with_stdio(false);
        int ans = 0;
        unordered_map<string, int> mp;

        for (int x = words.size() - 1; x >= 0; x--) {
            string word = words[x];
            int wordLength = word.size();
            
            string prefix = "", suffix = "";
            
            if (mp.find(word) != mp.end()) {
                ans += mp[word];
            }

            for (int i = 0; i < wordLength ; i++) {
                prefix += word[i];            
                suffix = word[wordLength - 1 - i] + suffix;  
                if (prefix == suffix) {
                    mp[prefix]++;
                } 
                cout<<prefix<<" "<<suffix;
            }
  
         cout<<endl;
        }

        return ans;
    }
};
