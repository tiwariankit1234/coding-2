#define  inty int,int,int
class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<long long>>dist(n,vector<long long>(k+2,INT_MAX));
        // storing cost and k
        priority_queue<tuple<inty>,vector<tuple<inty>>,greater<tuple<inty>>>pq;
        // have cost,k,node
        pq.push({0,0,src});
        dist[src][0]=0;
        while(pq.size()){
            auto [cost,currentk,node]=pq.top();
            if(node==dst)return cost;
            pq.pop();
            for(auto it:adj[node]){
             int adjNode=it.first,newcost=it.second;
             if(currentk<=(k) and dist[node][currentk]+newcost<dist[adjNode][currentk+1]){
                dist[adjNode][currentk+1]=cost+newcost;
                pq.push({cost+newcost,currentk+1,adjNode});
             }
            }
        }
        return -1;
    }
};