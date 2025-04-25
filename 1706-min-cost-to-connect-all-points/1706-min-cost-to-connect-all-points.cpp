class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int, int>& p) const {
            return hash<long long>()(((long long)p.first << 32) | p.second);
        }
    };

    int primMST(int n, unordered_map<pair<int, int>, int, hash_pair>& edges) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& [p, wt] : edges) {
            int u = p.first;
            int v = p.second;
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // undirected graph
        }

        vector<bool> inMST(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); // {weight, node}

        int totalWeight = 0;

        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;
            totalWeight += wt;

            for (auto& [v, w] : adj[u]) {
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }

        return totalWeight;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<pair<int, int>, int, hash_pair> mp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                mp[{i, j}] = wt;
                mp[{j, i}] = wt;
            }
        }

        return primMST(n, mp);
    }
};
