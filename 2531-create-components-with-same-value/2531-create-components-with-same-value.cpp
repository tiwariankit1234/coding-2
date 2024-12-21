class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values, int targetSum, int& count) {
        int sum = values[node];
        
        for (auto it : adj[node]) {
            if (it != parent) {
                sum += dfs(it, node, adj, values, targetSum, count);
            }
        }
        
        if (sum == targetSum) {
            count++;
            return 0; // Reset the sum as this forms a valid component
        }
        return sum;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        if (n == 1) return 0;

        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int result = 0;

        // Iterate over all possible component sums (divisors of totalSum)
        for (int targetSum = 1; targetSum <= totalSum; ++targetSum) {
            if (totalSum % targetSum == 0) {
                int count = 0;
                if (dfs(0, -1, adj, nums, targetSum, count) == 0) {
                    result = max(result, count - 1);
                }
            }
        }

        return result;
    }
};
