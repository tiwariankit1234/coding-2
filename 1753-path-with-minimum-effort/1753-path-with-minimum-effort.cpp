#define pii pair<int, int>

class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool possible(int threshold, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pii> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int newx = x + dir[k][0];
                int newy = y + dir[k][1];
                if (isValid(newx, newy, m, n) && !visited[newx][newy]) {
                    int diff = abs(grid[newx][newy] - grid[x][y]);
                    if (diff <= threshold) {
                        visited[newx][newy] = true;
                        q.push({newx, newy});
                    }
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0, high = 1e6, ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
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
