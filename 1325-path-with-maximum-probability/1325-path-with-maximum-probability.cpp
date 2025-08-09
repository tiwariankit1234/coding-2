#define pii pair<double,int>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pii>>adj(n);
        vector<double>dist(n,0.0);
        dist[start]=1.0;
        int k=edges.size();
        for(int i=0;i<k;i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<pii>pq;
        pq.push({1.0,start});
       
        while(pq.size()){
            auto [cost,node]=pq.top();
            
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.second;
                double nextcost=it.first;
                // cout<<node<<" "<<adjnode<<" "<<dist[node]<<" "<<dist[adjnode]<<" "<<dist[node]*nextcost<<" "<<dist[adjnode]<<endl;
                if( (dist[node]*nextcost)>dist[adjnode]){
                    dist[adjnode]=dist[node]*nextcost;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        // for(auto it:dist){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return dist[end];
        
    }
};