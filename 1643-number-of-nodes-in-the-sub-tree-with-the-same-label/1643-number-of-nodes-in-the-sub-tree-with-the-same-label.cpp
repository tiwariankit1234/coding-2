class Solution {
public:
    vector<int> ans;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, char> mp;
    vector<int> visited;

    vector<int> dfs(int i) {
        visited[i] = 1;
        vector<int> v(26,0);
        v.push_back(mp[i]);
        for (auto it : adj[i]) {
            if (visited[it] == 0) {
                vector<int> child = dfs(it);
               for(int j=0;j<26;j++){
                 v[j]+=child[j];
               }
            }
        }

        v[mp[i]-'a']++;
        ans[i]=v[mp[i]-'a'];

        return v;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        ans.clear();
        if(n==1)return {1};
        ans.resize(n, 0);
        visited.clear();
        visited.resize(n, 0);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Add the reverse direction for undirected graph
            mp[u] = labels[u];
            mp[v] = labels[v];
        }

        dfs(0);
        return ans;
    }
};