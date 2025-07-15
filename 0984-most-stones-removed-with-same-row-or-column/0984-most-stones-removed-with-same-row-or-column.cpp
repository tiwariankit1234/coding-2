class Solution {
public:
int dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
    visited[node]=1;
    int count=1;
    for(auto it:adj[node]){
        if(visited[it]==0){
            count+=dfs(it,adj,visited); 
        }
    }
    return count;

}
bool possible(vector<int>&a,vector<int>&b){
    return (a[0]==b[0])||(a[1]==b[1]);
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(possible(stones[i],stones[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                // cout<<"pehle"<<5<<endl;
              int size=dfs(i,adj,visited);
            //   cout<<"baad"<<5<<endl;
              count+=size-1;
            }
        }
        return count;
    
    }
};