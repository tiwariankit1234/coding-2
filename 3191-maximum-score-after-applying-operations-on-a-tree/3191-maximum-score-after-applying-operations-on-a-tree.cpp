#define ll long long
class Solution {
public:
    ll f(int node, int parent, vector<vector<int>>& adj, vector<int>& value, bool parentTaken) {
        if(adj[node].size()==1 and parentTaken==false and node!=0){
            return 0;
        }
        if (adj[node].size()==1 and parentTaken==true){
            return value[node];
        }
        // If parent took this node, we can't take it
        if (parentTaken) {
            ll total = value[node];
            for (int child : adj[node]) {
                if (child != parent) {
                    total += f(child, node, adj, value, true);
                }
            }
            return total;
        } else {
            // We have two options: take this node or don't take it
            ll take = value[node];
            for (int child : adj[node]) {
                if (child != parent) {
                    take += f(child, node, adj, value, parentTaken);
                }
            }

            ll notTake = 0;
            for (int child : adj[node]) {
                if (child != parent) {
                    notTake += f(child, node, adj, value, true);
                }
            }

            return max(take, notTake);
        }
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return f(0, -1, adj, values, false);
    }
};
