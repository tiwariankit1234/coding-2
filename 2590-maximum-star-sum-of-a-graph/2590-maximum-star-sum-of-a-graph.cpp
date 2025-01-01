class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size(),sum=0,maxsum=INT_MIN;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // for(auto it:adj){
        //     for(auto k:it){
        //         cout<<k<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=0;i<n;i++){
          if(adj[i].size()>0)  sort(adj[i].begin(),adj[i].end(),[&](int a,int b){
            return vals[a]>vals[b];
          });
        //   for(auto it:adj[i]){
        //     cout<<it<<" ";
        //   }
        //   cout<<endl;
            int j=0;
            int l=k;
            int sum=vals[i];
            // while(l-- and adj[i].size()==k){
            //    int node=adj[i][j++];
            //   if(i==3)cout<<node<<" ";
            //    sum+=vals[node];
            // }
            for(int j=0;j<k and j<adj[i].size();j++){
                if(vals[adj[i][j]]>0)
                sum+=vals[adj[i][j]];
            }
           
          
            // cout<<sum<<endl;
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};