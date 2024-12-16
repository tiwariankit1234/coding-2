class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // Priority queue: {steps, {row, col, remaining k}}
        priority_queue<pair<int, pair<int, pair<int, int>>>, 
                       vector<pair<int, pair<int, pair<int, int>>>>, 
                       greater<pair<int, pair<int, pair<int, int>>>>> pq;

        // Visited array: tracks the minimum obstacles removed to reach (row, col)
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        // Start from (0, 0)
        pq.push({0, {0, {0, k}}});
        visited[0][0][k] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second.first;
            int remainingK = it.second.second.second;

            // Check if we've reached the target
            if (row == n - 1 && col == m - 1)
                return steps;

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < m) {
                    int newK = remainingK - grid[newr][newc]; // Reduce k if there's an obstacle
                    if (newK >= 0 && !visited[newr][newc][newK]) {
                        visited[newr][newc][newK] = 1;
                        pq.push({steps + 1, {newr, {newc, newK}}});
                    }
                }
            }
        }

        // If no path is found
        return -1;
    }
};
