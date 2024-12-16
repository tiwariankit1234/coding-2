class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        int n = grid.size();
        int m = grid[0].size();

        // Start from (0, 0)
        pq.push({grid[0][0] == 1 ? 1 : 0, {0, 0}});
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Check if we reached the bottom-right corner
            if (row == n-1 && col == m-1)
                return (health > diff);

            // Explore all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < m && visited[newr][newc] == 0) {
                    visited[newr][newc] = 1;

                    // Update the difficulty for the new cell
                    if (grid[newr][newc] == 1)
                        pq.push({diff + 1, {newr, newc}});
                    else
                        pq.push({diff, {newr, newc}});
                }
            }
        }

        return false; // No path found
    }
};
