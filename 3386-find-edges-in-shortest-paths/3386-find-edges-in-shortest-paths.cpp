class Solution {
public:
typedef long long ll;
typedef pair<ll, ll> P;

vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    // Step 1: Build adjacency list representation of the graph
    vector<vector<P>> adj(n);
    int totalEdges = edges.size();
    
    for (int i = 0; i < totalEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // Step 2: Perform Dijkstra's algorithm to find the shortest distance from node 0
    vector<int> dist(n, INT_MAX);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});  // {distance, node}
    dist[0] = 0;
    
    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[node]) continue; // Skip outdated entries
        
        for (auto it : adj[node]) {
            int v = it.first;
            int w = it.second;
            if (dist[v] > dist[node] + w) {
                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    // If destination node (n-1) is unreachable, return all false
    vector<bool> ans(totalEdges, false);
    if (dist[n - 1] == INT_MAX) return ans;
    
    // Step 3: Backtrack from node n-1 to 0 to find edges in the shortest path
    vector<int> vis(n, 0);
    set<P> st; // Store shortest path edges
    queue<int> q;
    q.push(n - 1);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        if (vis[node]) continue;
        vis[node] = 1;
        
        for (auto it : adj[node]) {
            int v = it.first;
            int w = it.second;
            if (dist[node] - w == dist[v]) {
                st.insert({node, v});
                st.insert({v, node});
                q.push(v);
            }
        }
    }
    
    // Step 4: Mark edges in the shortest path as true in the result
    for (int i = 0; i < totalEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (st.count({u, v})) {
            ans[i] = true;
        }
    }
    
    return ans;
}
};