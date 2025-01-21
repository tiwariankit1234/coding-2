class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        // Adjacency list as sets for fast lookup
        vector<unordered_set<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        int ans = INT_MAX;

        // Iterate through all possible trios (i, j, k) with i < j < k
        for (int i = 1; i <= n; ++i) {
            for (auto j : adj[i]) {
                if (j <= i) continue; // Ensure i < j
                for (auto k : adj[j]) {
                    if (k <= j || adj[i].find(k) == adj[i].end()) continue; // Ensure i < j < k and form a trio

                    // Calculate the degree of the trio
                    int degree = (adj[i].size() - 2) + (adj[j].size() - 2) + (adj[k].size() - 2);
                    ans = min(ans, degree);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
