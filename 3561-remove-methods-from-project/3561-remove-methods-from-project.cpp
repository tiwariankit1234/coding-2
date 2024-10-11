class Solution {
public:
 
 void dfs1(int i,vector<int>adj[],vector<int>&visited,vector<int>&ans,int n){
    visited[i]=1;
   
    // cout<<"5"<<endl;
   
    for(auto child:adj[i]){
        if(visited[child]==0){
          dfs1(child,adj,visited,ans,n);
        }
    }  
      
      return ;
 }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
         
         vector<int>visited(n,0);
        for(auto it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>ans;

        dfs1(k,adj,visited,ans,n);

            // for(auto it:visited)
            // cout<<it<<endl;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                // cout<<"5"<<endl;
               ans.push_back(i);
            }
        }

        // check there is no internal edge calling suspicious node
           
   

        for(auto it:invocations){

    
         int a=it[0];
         
            int b=it[1];
            if(!visited[a] and visited[b]){
                ans.clear();
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        
        return ans;
    }
};