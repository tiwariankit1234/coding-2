class Solution {
public:
    bool bfs(int node, vector<int>&visited,vector<vector<int>>& graph){
        // visited me teen state hain -1 0 aur 1 -1 for not visited 
        // agar koi node hain aur uske neighbours unvisited hain toh
        // visited kardo with color alternate of color of that node
        // agar visited hain aur same color toh return false kar do 
        visited[node]=0;
        queue<pair<int,int>>q;
        int color=0;
        q.push({node,color});
        while(q.size()>0){
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
        for(int adjNode:graph[node]){
         if(visited[adjNode]==-1){
            visited[adjNode]=!color;
           q.push({adjNode,!color});
         }
        else if(visited[adjNode]==color)
        return false;
        }
       
    }
    return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        int n=graph[0].size();
         vector<int> visited(m, -1);
        for(int i=0;i<graph.size();i++){
            if(visited[i]==-1)
            if(bfs(i,visited,graph)==false)return 0;
        }
        return true;
    }
};