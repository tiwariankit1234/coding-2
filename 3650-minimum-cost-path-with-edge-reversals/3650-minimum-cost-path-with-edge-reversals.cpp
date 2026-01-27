#define pii pair<int, int>
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2*it[2]});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while (pq.size()) {
            auto [disty, node] = pq.top();
            pq.pop();
            for (auto [x, y] : adj[node]) {
                if (dist[node] + y < dist[x]) {
                    dist[x] = dist[node] + y;
                    pq.push({dist[x],x});
                }
            }
        }
        if(dist[n-1]==INT_MAX)return -1;
        return dist[n - 1];
    }
};