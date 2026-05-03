class Solution {
public:
    void dfs(int u, vector<bool>& inSubset, vector<bool>& visited,
             vector<vector<int>>& adj) {

        visited[u] = true;

        for (int v : adj[u]) {
            if (inSubset[v] && !visited[v]) {
                dfs(v, inSubset, visited, adj);
            }
        }
    }

    void solve(int i, vector<int>& nums, vector<vector<int>>& adj,
               vector<int>& curr, int& count) {

        int n = nums.size();

        if (i == n) {
            if (curr.empty()) return;

            // mark subset
            vector<bool> inSubset(n, false);
            int sum = 0;
            for (int x : curr) {
                inSubset[x] = true;
                sum += nums[x];
            }

            // DFS
            vector<bool> visited(n, false);
            dfs(curr[0], inSubset, visited, adj);

            // check connectivity
            for (int x : curr) {
                if (!visited[x]) return;
            }

            // check even sum
            if (sum % 2 == 0) count++;

            return;
        }

        // include
        curr.push_back(i);
        solve(i + 1, nums, adj, curr, count);
        curr.pop_back();

        // exclude
        solve(i + 1, nums, adj, curr, count);
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        vector<int> curr;

        solve(0, nums, adj, curr, count);

        return count;
    }
};