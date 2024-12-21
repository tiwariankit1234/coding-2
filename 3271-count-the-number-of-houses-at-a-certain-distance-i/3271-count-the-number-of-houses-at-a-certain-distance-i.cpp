class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int>ans(n+1,0);
        vector<vector<int>>adj(n+1,vector<int>(n+1,5000));
        for(int i=1;i<(n);i++){
          adj[i][i+1]=1;
          adj[i][i]=0;
          adj[i+1][i]=1;
        }
        if(x!=y){
        adj[x][y]=1;
        adj[y][x]=1;
        }
        else if(x==y){
            adj[x][y]=0;
        }
        adj[n][n]=0;

        // for(auto it:adj){
        //     for(auto k:it){
        //         cout<<k<<" ";
        //     }
        //     cout<<endl;
        // }

         for(int via=1;via<(n+1);via++){
             for(int i=1;i<(n+1);i++){
                 for(int j=1;j<(n+1);j++){
                    
                    adj[i][j]=min(adj[i][via]+adj[via][j],adj[i][j]);
                 }
             }
         }

         for(int i=1;i<(n+1);i++){
                 for(int j=1;j<(n+1);j++){
                    if(adj[i][j]>0){
                        ans[adj[i][j]]++;
                    }
                 }
         }  
         ans.erase(ans.begin());
              return ans;
        }
    
};