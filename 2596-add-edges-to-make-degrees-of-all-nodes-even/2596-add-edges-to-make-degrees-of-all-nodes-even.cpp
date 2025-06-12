class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        
        for (vector<int>& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        vector<int> odds;
        for (int i = 1; i <= n; i++) {  // Start from 1, not 0
            if (adj[i].size() % 2 != 0) {
                odds.push_back(i);
            }
        }

        if (odds.size() == 0) return true;
        if (odds.size() > 4 || odds.size() % 2 != 0) return false;

        if (odds.size() == 2) {
            int a = odds[0], b = odds[1];
            if (adj[a].find(b) == adj[a].end()) return true;
            // Try to connect both to some common unused node
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b &&
                    adj[a].find(i) == adj[a].end() &&
                    adj[b].find(i) == adj[b].end()) {
                    return true;
                }
            }
            return false;
        }

        if (odds.size() == 4) {
            int a = odds[0], b = odds[1], c = odds[2], d = odds[3];
            return (
                (adj[a].find(b) == adj[a].end() && adj[c].find(d) == adj[c].end()) ||
                (adj[a].find(c) == adj[a].end() && adj[b].find(d) == adj[b].end()) ||
                (adj[a].find(d) == adj[a].end() && adj[b].find(c) == adj[b].end())
            );
        }

        return false;
    }
};
