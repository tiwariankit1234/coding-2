class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        int maxsum = INT_MIN;
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Iterate through each node
        for (int i = 0; i < n; i++) {
            // Sort neighbors based on their values in descending order
            sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
                return vals[a] > vals[b];
            });

            // Compute star sum
            int sum = vals[i]; // Start with the value of the current node
            for (int j = 0; j < k && j < adj[i].size(); j++) {
                if (vals[adj[i][j]] > 0) { // Only add positive contributions
                    sum += vals[adj[i][j]];
                }
            }

            // Update the maximum star sum
            maxsum = max(maxsum, sum);
        }

        return maxsum;
    }
};
