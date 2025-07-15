class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};


class Solution {
public:


    vector<vector<string>> accountsMerge(vector<vector<string>>& adj) {
        int n=adj.size();
        DisjointSet dsu(n);
        unordered_map<string,int>mp;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            int account_size=adj[i].size();
            for(int j=1;j<account_size;j++){
               if(mp.find(adj[i][j])==mp.end()){
                mp[adj[i][j]]=i;
               }
               else{
                dsu.unionByRank(i,mp[adj[i][j]]);
               }
            }
        }
       map<int,vector<string>>mp2;
        for(auto it:mp){
          string name=it.first;
          int idx=it.second;
          int parent=dsu.findUPar(idx);
          mp2[parent].push_back(name);
        }
        for(auto it:mp2){
            vector<string>newstring;
           int idx=it.first;
            newstring.push_back(adj[idx][0]);
            for(auto k:it.second){
                    newstring.push_back(k);
            }
            sort(newstring.begin()+1,newstring.end());
            ans.push_back(newstring);
        }

      return ans;
    }
};