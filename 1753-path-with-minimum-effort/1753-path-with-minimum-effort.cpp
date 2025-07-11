#define pii pair<int, int>

class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Min-heap: {effort_so_far, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [effort, x, y] = pq.top();
            pq.pop();

            // Goal reached
            if (x == m - 1 && y == n - 1)
                return effort;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));

                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.emplace(newEffort, nx, ny);
                    }
                }
            }
        }

        return 0; // Should never reach here
    }
};
