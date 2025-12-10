class Solution {
public:
vector<int>count;
vector<int>res;
void dfs1(int u,int p){
    for(int v:adj[u]){
        if(v==p)continue;
        dfs1(v,u);
        count[u]+=count[v];
        res[u]+=res[v]+count[v];
    }
}
void dfs2(int u,int p){
    for(int v:adj[u]){
        if(v==p)continue;
        res[v]=res[u]-count[v]+(n-count[v]);
        dfs2(v,u);
    }
}
vector<vector<int>>adj;
int n;
    vector<int> sumOfDistancesInTree(int k, vector<vector<int>>& edges) {
         n=k;
        adj.assign(n,{});
        count.assign(n,1);
        res.assign(n,0);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return res;
    }
};