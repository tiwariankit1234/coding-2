class Solution {
public:
    int R, C;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(R, vector<int>(C, 0));

        // Flood first 'day' cells
        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        // Start BFS from top row
        for (int c = 0; c < C; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                visited[0][c] = true;
            }
        }

        // BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == R - 1) return true;

            for (auto &d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                    !visited[nr][nc] && grid[nr][nc] == 0) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        R = row;
        C = col;

        int low = 0, high = row * col;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canCross(mid, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
