#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list
        unordered_map<int, vector<int>> adj;
        for (const auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
        }

        // To track visited nodes and detect cycles
        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> result;

        // DFS function
        function<bool(int)> dfs = [&](int node) {
            if (visited[node] == 1) return false; // Cycle detected
            if (visited[node] == 2) return true;  // Already processed

            visited[node] = 1; // Mark as visiting

            for (int neighbor : adj[node]) {
                if (!dfs(neighbor)) {
                    return false; // Cycle detected
                }
            }

            visited[node] = 2; // Mark as visited
            result.push_back(node); // Add to result (post-order)
            return true;
        };

        // Perform DFS for all unvisited nodes
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i)) {
                    return {}; // Cycle detected, return empty array
                }
            }
        }

        // Reverse the result to get the topological order
        reverse(result.begin(), result.end());
        return result;
    }
};