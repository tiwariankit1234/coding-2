class Solution {
public:
    bool possible(string &longer, string &shorter) {
        int m = longer.size(), n = shorter.size();
        if (m != n + 1) return false;

        int i = 0, j = 0;
        bool removed = false;

        while (i < m) {
            if (j < n && longer[i] == shorter[j]) {
                i++; 
                j++;
            }
            else {
                if (removed) return false;
                removed = true;
                i++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // sort by length
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int bestLen = 1, lastIndex = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;  
            for (int j = 0; j < i; j++) {
                if (possible(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if (dp[i] > bestLen) {
                bestLen = dp[i];
                lastIndex = i;
            }
        }

        // OPTIONAL: print the chain
        vector<string> chain;
        chain.push_back(words[lastIndex]);
        while (parent[lastIndex] != lastIndex) {
            lastIndex = parent[lastIndex];
            chain.push_back(words[lastIndex]);
        }

        reverse(chain.begin(), chain.end());

        for (auto &w : chain) cout << w << " ";
        cout << endl;

        return bestLen;
    }
};
