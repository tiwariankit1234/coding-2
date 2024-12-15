class Solution {
public:
 bool bfs(vector<vector<int>>&adjList,vector<int>&visited,int start,int end){
        queue<int>q;
          visited[start]=1;// first visited
        q.push(start);        // then push
        
        while(q.size()!=0){
            int city=q.front();
            q.pop();

            if(city==end)return true;
          
        for(auto adjcity:adjList[city]){
           if (!visited[adjcity]){
        visited[adjcity]=1;
        
           q.push(adjcity);
           
         }
         
          }
      }
      return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
            vector<vector<int>>adjList(n); // it is list
         for(auto it:edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
         }
        vector<int>visited(n,0);

      return bfs(adjList,visited,source, destination);
        
    }
};