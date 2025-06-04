class Solution {
public:
    //TC:O(N * H); SC:O(N^2); H:Height of tree
    vector<pair<int, int>> change; //{node, new_parent} Used to record the rearranged of edges
    vector<int> adj[100000];  // Adjacency list for the tree
    
    void dfs(int node, string& s,vector<int>mp,vector<int>&visited) { //Traverse upwards from original to node 0
        char ch=s[node];
        visited[node]=1;
       
        {
            if(mp[ch-'a']>=0)
            change.push_back({node,mp[ch-'a']});
         
        }
       
        mp[ch-'a']=node;
      
        for (auto it:adj[node]){
            if(visited[it]==0){
            dfs(it,s,mp,visited);
            }
        }
        
        return ;
    }
    
    void countChildren(int node, vector<int>& res, vector<vector<int>>& newAdj) {
        for (int child : newAdj[node]) {
            countChildren(child, res, newAdj);
            res[node] += res[child];
        }
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
      
        
    
        int n = parent.size();
        vector<int> res(n, 1);
         
        vector<int>visited(n,0);
        for(int i=1; i<n; i++) {
            adj[parent[i]].push_back(i);
        }
           vector<int>mp(26,-1);
        dfs(0,s,mp,visited);
    
        for (auto itr : change) parent[itr.first] = itr.second; //Rearrange the edges
           vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[parent[i]].push_back(i);
        }

    
        
        countChildren(0, res,newAdj);
        
        return res;
    }
};