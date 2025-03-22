class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adj,
             int& totaledges, int& vertices) {
        visited[node] = 1;
        vertices++;
        totaledges += adj[node].size();
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                dfs(it, visited, adj, totaledges, vertices);
            }
        }
        
        if (totaledges == (vertices*(vertices-1)))
            return true;
        else
            return false;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(n); // it is list
        for (auto it : edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                int totaledges = 0, vertices = 0;
                count += dfs(i, visited, adjList, totaledges, vertices);
            }
        }
         return count;
    }
   

}
;