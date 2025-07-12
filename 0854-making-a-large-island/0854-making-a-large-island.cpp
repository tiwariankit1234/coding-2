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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                count++;
            }
        }
        if(count==m*n)return count;
         cout<<5<<endl;
        DisjointSet dsu(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  for(int k=2;k<4;k++){
                       int newx=i+dir[k][0],newy=j+dir[k][1];
                       if(newx>=0 and newy>=0 and newx<m and newy<n and grid[newx][newy]==1){
                           dsu.unionBySize(i*n+j,newx*n+newy);
                       }
                  }
                }
            }
        }
        cout<<5<<endl;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>s;
                    for(int k=0;k<4;k++){
                        int newx=i+dir[k][0],newy=j+dir[k][1];
                        if(newx>=0 and newx<m and newy>=0 and newy<n and grid[newx][newy]==1){
                         s.insert(dsu.findUPar(newx*n+newy));
                        }
                    }
                    int wholesize=0;
                   for(auto it:s){
                    wholesize+=dsu.size[it];
                   }
                   ans=max(ans,wholesize+1);

                }
            }
        }
        return ans;
    }
};