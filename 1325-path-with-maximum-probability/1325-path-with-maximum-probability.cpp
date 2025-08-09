class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using pii = pair<double, int>;
        vector<vector<pii>> adj(n);
        vector<double> dist(n, 0.0);

        int k = edges.size();
        for (int i = 0; i < k; i++) {
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        priority_queue<pii> pq;
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (prob < dist[node]) continue;

            for (auto [edgeProb, adjnode] : adj[node]) {
                if (dist[node] * edgeProb > dist[adjnode]) {
                    dist[adjnode] = dist[node] * edgeProb;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        return dist[end_node];
    }
};
