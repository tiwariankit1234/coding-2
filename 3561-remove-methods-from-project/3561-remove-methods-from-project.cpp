class Solution {
public:
    // DFS to find all methods that are suspicious (reachable from method k)
    void dfs(int i, const std::vector<int> adj[], std::unordered_set<int>& suspicious) {
        suspicious.insert(i); // Mark this method as suspicious

        for (auto child : adj[i]) {
            if (suspicious.find(child) == suspicious.end()) {
                dfs(child, adj, suspicious); // Recursively mark all invoked methods
            }
        }
    }

    std::vector<int> remainingMethods(int n, int k, const std::vector<std::vector<int>>& invocations) {
        std::vector<int> adj[n]; // Adjacency list to represent the graph
        std::unordered_set<int> suspicious; // Set to track suspicious methods

        // Build the adjacency list
        for (const auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        // Perform DFS starting from method k to find all suspicious methods
        dfs(k, adj, suspicious);

        // Check if any non-suspicious method invokes a suspicious method
        for (const auto& it : invocations) {
            int invoker = it[0], invoked = it[1];
            if (suspicious.find(invoked) != suspicious.end() && suspicious.find(invoker) == suspicious.end()) {
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);// Return all methods if any suspicious is invoked by a non-suspicious
            }
            return ans;
        }
        }   

        // Collect remaining methods that are not in the suspicious set
        std::vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (suspicious.find(i) == suspicious.end()) {
                remaining.push_back(i);
            }
        }

        return remaining; // Return the remaining methods
    }
};
