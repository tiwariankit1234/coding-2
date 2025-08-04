class Solution {
public:

class DisjointSet {

public:
    vector<int> rank, parent,size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

   void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


    vector<int> processQueries(int c, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
     DisjointSet dsu(c+1);

        for(auto it:edges){
            dsu.unionBySize(it[0],it[1]);
        }
        map<int,set<int>>mp;
        for(int i=1;i<=c;i++){
           int par=dsu.findUPar(i);
           mp[par].insert(i);
        }
        vector<int>ans;
        for(auto it:queries){
            int type=it[0];
            if(type==1){
                auto& temp=mp[dsu.findUPar(it[1])];
                if(temp.size()==0){
                    ans.push_back(-1);
                }
                else{
                    if(temp.contains(it[1])){
                        ans.push_back(it[1]);
                    }
                    else{
                        ans.push_back(*temp.begin());
                    }
                }
               
            }
            else{
                auto& temp=mp[dsu.findUPar(it[1])];
                if(temp.size())
                temp.erase(it[1]);
            }
        }
          return ans;
    }
};