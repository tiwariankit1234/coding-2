class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>outdegree(n,0);
        for(int i=0;i<n;i++){
          for(int j=0;j<graph[i].size();j++){
            outdegree[i]++;
            adj[graph[i][j]].push_back(i);
          }
        }
       
        // for(int i=0;i<n;i++){
        //     cout<<outdegree[i]<<" ";
            
        // }
        // cout<<endl;
        queue<int>q;

        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                // cout<<i<<endl;
               q.push(i);
            }
        }
        vector<int>ans;
        while(q.size()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int adjNode:adj[node]){
                outdegree[adjNode]--;
                if(outdegree[adjNode]==0){
                    q.push(adjNode);
                   
                }
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};