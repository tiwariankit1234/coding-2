class Solution {
public:
int repeat=0;
bool  dfs(int node, vector<vector<int>>&adj,vector<int>&visited,vector<int>&cycle,int parent){
    visited[node]=1;
    // cout<<node<<endl;
    for(auto child:adj[node]){
        if(visited[child]==0 and repeat==0){
           bool t=dfs(child,adj,visited,cycle,node);
         if(t==true){
            if(repeat==node){
                cycle[node]=true;
                return false;
            }
            cycle[node]=true;
            return true;
         }
        }
        else if(visited[child]==1 and child!=parent){
            repeat=child;
            cycle[node]=true;
            return true;
        }
    }
    return false;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n = edges.size();
           vector<vector<int>>adj(n+1);
           vector<int>visited(n+1),cycle(n+1);
           for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
           }
         
        dfs(1,adj,visited,cycle,-1);
        for(int i=n-1;i>=0;i--){
            if(cycle[edges[i][0]]==1 and cycle[edges[i][1]]==1)
            return edges[i];
        }
        return {};
    }
};