class Solution {
public:
    int maxprofit = 0;

    void f(int node, int maxTime, int profit,
           unordered_set<int>& s,
           vector<vector<pair<int,int>>>& adj,
           vector<int>& values) {
        
        if (node == 0) {
            maxprofit = max(maxprofit, profit);
        }

        for (auto [adjnode, time] : adj[node]) {
            if (maxTime - time >= 0) {
                bool firstVisit = !s.count(adjnode);
                if (firstVisit) {
                    s.insert(adjnode);
                    f(adjnode, maxTime - time, profit + values[adjnode], s, adj, values);
                    s.erase(adjnode); // backtrack
                } else {
                    f(adjnode, maxTime - time, profit, s, adj, values);
                }
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        unordered_set<int> s;
        s.insert(0); // mark start as visited
        f(0, maxTime, values[0], s, adj, values);

        return maxprofit;
    }
};
