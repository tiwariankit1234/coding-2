class Solution {
public:
    int ans = INT_MIN;
    int f(int node, int parent, vector<vector<int>>& adj, string& s) {
        int firstmax = 0, secondmax = 0, maxlength = 0;
        for (auto it : adj[node]) {
            if (it != parent) {
                int m = f(it, node, adj, s);
                if (m >= firstmax) {
                    secondmax = firstmax;
                    firstmax = m;
                } else if (m >= secondmax) {
                    secondmax = m;
                }
            }
        }
        ans = max(ans, firstmax + secondmax + 1);

        if (node != 0 and s[node] == s[parent])
            return 0;
        return max(firstmax, secondmax) + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        f(0, -1, adj, s);
        return ans;
    }
};