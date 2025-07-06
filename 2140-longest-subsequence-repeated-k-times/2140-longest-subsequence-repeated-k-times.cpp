class Solution {
public:
    string ans = "";
    int largest = 0;

    // Check if s * k is a subsequence of t
    bool isSubsequencepresent(string& s, string& t, int k) {
        string repeated = "";
        for (int i = 0; i < k; ++i) repeated += s;
        int i = 0, j = 0;
        while (i < t.size() && j < repeated.size()) {
            if (t[i] == repeated[j]) {
                ++j;
            }
            ++i;
        }
        return j == repeated.size();
    }

    void generate_subs(vector<int>& freq, int k, string s, string& t) {
        int maxSize = t.size() / k;
        if (!isSubsequencepresent(s, t, k)) return;

        if ((int)s.size() > largest || ((int)s.size() == largest && s > ans)) {
            ans = s;
            largest = s.size();
        }

        for (int j = 25; j >= 0; --j) {
            if (freq[j] > 0) {
                freq[j]--;
                generate_subs(freq, k, s + char('a' + j), t);
                freq[j]++;
            }
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        // Remove characters with frequency less than k
        for (int i = 0; i < 26; ++i) {
            if (freq[i] < k) freq[i] = 0;
        }

        for (int i = 25; i >= 0; --i) {
            if (freq[i] > 0) {
                freq[i]--;
                string start = "";
                start += (char)('a' + i);
                generate_subs(freq, k, start, s);
                freq[i]++;
            }
        }

        return ans;
    }
};
