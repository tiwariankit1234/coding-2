class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    bool bfs(int i, int j, char ch, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = true;

        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{i, j}, {-1, -1}});  // root has no parent

        while (!q.empty()) {
            auto [curr, parent] = q.front(); q.pop();
            int x = curr.first, y = curr.second;
            int px = parent.first, py = parent.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k][0], ny = y + dir[k][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == ch) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({{nx, ny}, {x, y}});
                    } else if (!(nx == px && ny == py)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (bfs(i, j, grid[i][j], grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
