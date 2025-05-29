class Solution {
public:
    int dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
        int ans = INT_MAX;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        vector<bool> visited(V, false);

        distTo[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            for (auto& it : adj[node]) {
                int v = it.first;
                int w = it.second;
                ans = min(ans, w);  // track min edge weight

                if (dis + w < distTo[v]) {
                    distTo[v] = dis + w;
                    pq.push({distTo[v], v});
                }
            }
        }

        return ans;
    }

    int minScore(int k, vector<vector<int>>& roads) {
        int n = 0;
        for (auto& r : roads) {
            n = max({n, r[0], r[1]});  // max node index
        }

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        return dijkstra(n + 1, adj, 1);
    }
};
