
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n==1)return 0;
        using pii = pair<int, int>; // (time, node)
        vector<int> cost(n, INT_MAX);
        vector<vector<tuple<int, int, int>>> adj(n); // {to, start, end}

        // Build adjacency list
        for (auto& e : edges) {
            int u = e[0], v = e[1], start = e[2], end = e[3];
            adj[u].emplace_back(v, start, end);
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0}); // (time, node)
        cost[0] = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            cout<<time<<" "<<node<<endl;

            // already found a better path

            for (auto& [next, start, end] : adj[node]) {
                int arrival=0;
                if(time>=start and time<=end){
                    arrival=time;
                }
                else if(time<start){
                    arrival=max(start,time);
                }
                else{
                    continue;
                }
 
                if (arrival>=start and arrival <= end && arrival+1 < cost[next]) {
                    cost[next] = arrival+1;
                    cout<<arrival+1<<" "<<node<<" "<<next<<endl;
                    pq.push({arrival+1, next});
                }
            }
        }

        return cost[n - 1] == INT_MAX ? -1 : cost[n - 1];
    }
};
