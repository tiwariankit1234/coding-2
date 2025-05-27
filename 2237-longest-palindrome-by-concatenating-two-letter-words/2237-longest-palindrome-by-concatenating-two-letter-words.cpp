class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        map<string, int> mp;
        for (auto it : words)
            mp[it]++;
        int size = 0;
        bool odd = false;
        for (auto it : mp) {
            string s = it.first;
            string t = s;
            reverse(t.begin(), t.end());
            if (s[0] == s[1]) {
                if (it.second != 1) {
                    if (it.second & 1) {
                        int freq = it.second / 2;
                        // ans will be length*freq*symmetry
                        size += freq * 2 * 2;
                        if (!odd) {
                            odd = true;
                            // ans will be length*1;
                            size +=2;
                        }
                    } else if ((it.second & 1)==0) {
                        int freq = it.second / 2;
                        size += freq * 2 * 2;
                    }
                } else if (it.second == 1 and odd == false) {
                    size += 1 * 2;
                    odd=true;
                }
            } else if (mp[s]>0 and mp.find(t) != mp.end()) {
                int freq = min(mp[s], mp[t]);
                size += freq * 2 * 2;
                mp[s]=0;
                mp[t]=0;
            }  
        }
        return size;
    }
};