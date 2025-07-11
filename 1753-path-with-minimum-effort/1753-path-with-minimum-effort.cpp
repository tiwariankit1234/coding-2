#define pii pair<int,int> 
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isValid(int x,int y,vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        return x>=0 and x<m and y>=0 and y<n;
    }
    bool possible(int threshold, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> visited(m * n+n,false);
         pq.push({0, 0});
        int mini = INT_MAX;
          visited[0]=true;
        while (pq.size()) {
            auto [cost, node] = pq.top();
           
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int x = node / n, y = node % n;
                if (x == m - 1 and y == n - 1)
                    return true;
                int newx = x + dir[k][0], newy = y + dir[k][1];
                // cout<<cost<<" "<<node<<" "<<x<<" "<<y<<" "<<newx<<" "<<newy<<endl;
                if (isValid(newx, newy, grid) and
                    abs(grid[newx][newy] - grid[x][y]) <= threshold and
                    visited[newx * n + newy] == false) {
                    visited[newx * n + newy] = true;
                    pq.push({threshold, newx * n + newy});
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int low = 0, high = 1e6, ans = INT_MAX;
        while (low <= high) {
            
            int mid = (low + high)/2;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if (possible(mid, heights)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};