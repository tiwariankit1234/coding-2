class Solution {
public:
    int dx[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int dijkstra(int x, int y, vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        
        priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int, int>> >, greater<> > pq;
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[x][y] = 0;
        pq.push({0, {x, y}});
        
        while (!pq.empty()) {
            auto [dis, pos] = pq.top();
            pq.pop();
            
            int cx = pos.first, cy = pos.second;
            
          
            
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k][0];
                int ny = cy + dx[k][1];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int extraCost = (nx+ny)%2==0?2:1; // Move right/left cost 1, up/down cost 2
                    int arriveTime =max( dis,moveTime[nx][ny]);
                    arriveTime+=extraCost;
               
                    
                    if (arriveTime < dist[nx][ny]) {
                        dist[nx][ny] = arriveTime;
                        // cout<<nx<<" "<<ny<<" "<<arriveTime<<" "<<moveTime[nx][ny]<<endl;
                        pq.push({arriveTime, {nx, ny}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
    
    int minTimeToReach(vector<vector<int>>& moveTime) {
        return dijkstra(0, 0, moveTime);
    }
};
