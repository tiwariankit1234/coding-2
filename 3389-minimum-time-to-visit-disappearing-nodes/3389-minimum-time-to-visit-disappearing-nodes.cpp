class Solution {
public:
typedef pair<int, int> pii;  // {distance, node}
vector<int>ans;
vector<int> dijkstra(int n, vector<vector<pii>>& adj,vector<int>&disappear,int src) {
    vector<int> dist(n, INT_MAX);  // Distance array
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});  // {distance, node}
   
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
      
        if (d > dist[u]) continue;  // Skip if we already have a better path

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w and disappear[v]>(dist[u]+w)) {
                dist[v] = dist[u] + w;
               
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        ans.clear();
        ans.resize(n,0);
         vector<vector<pair<int, int>>> adj(n);  // adj[u] = {v, weight}

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if(u!=v)
        adj[u].push_back({v, w});
        if(v!=u)
      adj[v].push_back({u, w});
    }
          vector<int>dist=dijkstra(n,adj,disappear,0);
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        return dist;
    }
};