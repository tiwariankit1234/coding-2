class DisjointSet {
public:
 vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
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
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet dsu(n - 1);
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if ((stones[i][0] == stones[j][0]) ||
        //             stones[i][1] == stones[j][1]) {
        //             dsu.unionByRank(i, j);
        //         }
        //     }
        // }
        unordered_map<int,vector<int>>mpx,mpy;
       for(int i=0;i<n;i++){
        mpx[stones[i][0]].push_back((i));
       }
       for(int i=0;i<n;i++){
        mpy[stones[i][1]].push_back(i);
       }
       for(auto it:mpx){
        vector<int>temp=it.second;
        int i=0;
        int n=temp.size();
        while(i<(n-1)){
            dsu.unionBySize(temp[i],temp[i+1]);
            i+=1;
        }
       }
    
    // for(auto it:mpx){
    //     cout<<it.first<<" ";
    //     for(auto k:it.second)
    //     cout<<k<<" ";
    //   cout<<endl;
    // }
    // cout<<"mpy"<<endl;
    // for(auto it:mpy){
    //     cout<<it.first<<" ";
    //     for(auto k:it.second)
    //     cout<<k<<" ";

    //     cout<<endl;
    // }

       for(auto it:mpy){
        vector<int>temp=it.second;
        int i=0;
        int n=temp.size();
        while(i<(n-1)){
            dsu.unionBySize(temp[i],temp[i+1]);
            i+=1;
        }
       }

        int count = 0;
        for (int i = 0; i < dsu.parent.size(); i++) {
            if (dsu.findUPar(i) == i) {
                count++;
            }
        }
        return (n - count);
    }
};