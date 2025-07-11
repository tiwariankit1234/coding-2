#include <vector>
#include <queue>
#include <climits>
#include <algorithm> // For std::sort
#include <numeric>   // For std::iota

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // --- Build Adjacency List ---
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        // --- Pass 1: Standard Dijkstra to find shortest times ---
        
        std::vector<long long> shortestTime(n, LLONG_MAX);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>,
                       std::greater<std::pair<long long, int>>> minHeap;

        shortestTime[0] = 0;
        minHeap.emplace(0, 0); // {time, node}

        while (!minHeap.empty()) {
            long long currTime = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();

            if (currTime > shortestTime[currNode]) {
                continue;
            }

            for (auto& edge : graph[currNode]) {
                int neighborNode = edge.first;
                int roadTime = edge.second;
                if (currTime + roadTime < shortestTime[neighborNode]) {
                    shortestTime[neighborNode] = currTime + roadTime;
                    minHeap.emplace(shortestTime[neighborNode], neighborNode);
                }
            }
        }
        
        // At this point, `shortestTime` array is fully populated.

        // --- Pass 2: Count paths using the calculated shortest times ---
        
        std::vector<long long> pathCount(n, 0);
        pathCount[0] = 1;

        // Create a list of nodes to sort them by distance
        std::vector<int> nodes(n);
        std::iota(nodes.begin(), nodes.end(), 0); // Fills nodes with 0, 1, 2, ...

        // Sort nodes based on their shortest time from the source
        // This gives us a topological ordering of the implicit shortest-path DAG
        std::sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return shortestTime[a] < shortestTime[b];
        });

        // Iterate through nodes in increasing order of their shortest time
        for (int u : nodes) {
            // If a node is unreachable, its time will be LLONG_MAX, skip it
            if (shortestTime[u] == LLONG_MAX) continue;
            
            // For the current node `u`, update the path counts of its neighbors `v`
            for (auto& edge : graph[u]) {
                int v = edge.first;
                int roadTime = edge.second;

                // If the edge u->v is part of a shortest path to v
                if (shortestTime[u] + roadTime == shortestTime[v]) {
                    // Add the number of ways to reach u to the number of ways to reach v
                    pathCount[v] = (pathCount[v] + pathCount[u]) % MOD;
                }
            }
        }
        
        return pathCount[n - 1];
    }
};