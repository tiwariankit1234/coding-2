#include <bits/stdc++.h>
using namespace std;

struct KeyHash {
    size_t operator()(const tuple<int,int,int,int>& t) const {
        auto [a,b,c,d] = t;
        return ((a*1315423911u + b*2654435761u) ^ (c*97531u + d*83123u));
    }
};

class Solution {
public:
    unordered_map<tuple<int,int,int,int>, int, KeyHash> mp;

    int f(int l, int r, int leftidx, int rightidx, vector<int>& cuts) {
        if (leftidx > rightidx) return 0;  // no cuts available

        auto key = make_tuple(l, r, leftidx, rightidx);
        if (mp.find(key) != mp.end()) return mp[key];

        int cost = INT_MAX;
        for (int j = leftidx; j <= rightidx; j++) {
            int newcost = (r - l) 
                        + f(l, cuts[j], leftidx, j - 1, cuts) 
                        + f(cuts[j], r, j + 1, rightidx, cuts);
            cost = min(cost, newcost);
        }

        return mp[key] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return f(0, n, 0, (int)cuts.size() - 1, cuts);
    }
};
