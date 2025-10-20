#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ans = "";
    vector<int> freq;

    void f(int idx, string &t, string &target) {
        if ((int)t.size() == (int)target.size()) {
            if ((t > target) && (ans == "" || t < ans)) {
                ans = t;
            }
            return;
        }

        int fidx = target[idx] - 'a';

        // Try using same char
        if (freq[fidx] > 0) {
            t.push_back('a' + fidx);
            freq[fidx]--;
            f(idx + 1, t, target);
            freq[fidx]++;
            t.pop_back();
        }

        // Try using greater char
        for (int i = fidx + 1; i < 26; i++) {
            if (freq[i] > 0) {
                t.push_back('a' + i);
                freq[i]--;
                string temp = t;
                for (int j = 0; j < 26; j++) {
                    temp.append(freq[j], 'a' + j);
                }
                if ((temp > target) && (ans == "" || temp < ans)) {
                    ans = temp;
                }
                freq[i]++;
                t.pop_back();
            }
        }
    }

    string lexGreaterPermutation(string s, string target) {
        if (s == target) {
            string next = s;
            if (next_permutation(next.begin(), next.end())) {
                if (next > target) return next;
            }
            return "";
        }

        freq.assign(26, 0);
        for (char c : s) freq[c - 'a']++;

        ans = "";
        string t = "";
        f(0, t, target);
        return ans;
    }
};
