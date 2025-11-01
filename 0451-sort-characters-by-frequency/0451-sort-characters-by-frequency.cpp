#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        sort(s.begin(), s.end(), [&](char a, char b) {
            if (mp[a] == mp[b])
                return a < b; // optional: sort lexicographically if freq equal
            return mp[a] > mp[b]; // higher frequency first
        });

        return s;
    }
};
