class Solution {
public:
    int min_ans;
    int m, n;
    // Visited array: [cell_index][current_xor]
    vector<vector<bool>> visited;

    void f(int i, int j, int current_xor, vector<vector<int>>& grid) {
        // Current cell ki value ko apne raste ke XOR mein jod lo
        current_xor ^= grid[i][j];

        // 1. Base Case: Agar aakhri cell (bottom-right) par pahunch gaye
        if (i == m - 1 && j == n - 1) {
            min_ans = min(min_ans, current_xor);
            return;
        }

        // 2D grid index (i, j) ko 1D index mein convert kiya (0 to 999)
        int idx = i * n + j;

        // 2. Memoization / Pruning: 
        // Agar is cell par SAME xor value ke saath pehle aa chuke hain, toh ruk jao.
        if (visited[idx][current_xor]) return;
        
        // Mark current state as visited
        visited[idx][current_xor] = true;

        // 3. Recursive Calls: Down aur Right jao
        if (i + 1 < m) {
            f(i + 1, j, current_xor, grid);
        }
        if (j + 1 < n) {
            f(i, j + 1, current_xor, grid);
        }
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // m * n <= 1000 constraints ke hisaab se max 1000 cells hain.
        // Max XOR <= 1023 ho sakta hai. 
        // Toh hum 1000 x 1024 ka boolean array banayenge (~1 MB space).
        visited.assign(m * n, vector<bool>(1024, false));
        
        // Answer ko maximum possible XOR (1024) se initialize kar diya
        min_ans = 1024; 

        // Start from (0,0) with initial XOR as 0
        f(0, 0, 0, grid);

        return min_ans;
    }
};