class Solution {
public:

 int dfs(int node,int parent,vector<vector<int>>&adj,vector<int>& values,int k,int& count){

    // if(!(node->left) and !(node->right))return node->val;
      int sum=0;
    for(auto it:adj[node]){
        if(it!=parent){
            sum+=dfs(it,node,adj,values,k,count);
           
            sum=sum%k;
        }
    }
    sum+=values[node];
     sum%=k;
     if(sum==0)count++;
    return sum ;
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
       
      vector<vector<int>>adj(n);

      for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }
      int count=0;

      dfs(0,-1,adj,values,k,count);
     return count;
        
    }
};