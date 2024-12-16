class Solution {
    // {right, down, left, up}
    const int dirs[5] = {0, 1, 0, -1, 0};
    
    int memo[51][51][101];
    int n, m;
    bool dfs(vector<vector<int>> &grid, int i, int j, int health){
        // Bounds Check + Visited Check + Health Check
        if(min(i, j) < 0 || i == n || j == m || grid[i][j] == -1 || health == 0) 
            return false;
        
        // Memoization : )
        if(memo[i][j][health] !=- 1) 
            return memo[i][j][health];
        
        int delta = grid[i][j];
        health -= delta;
        
       // Base  Case
        if(i == n - 1 && j == m - 1)
            return health >= 1;
        
        // mark visited
        grid[i][j] = -1;
        for(int k = 0; k < 4; k++){
            int newI = i + dirs[k], newJ = j + dirs[k + 1];
            if(dfs(grid, newI, newJ, health))
                return memo[i][j][health] = true;
        }
        
        // revert visited changes, to explore other possiblities
        grid[i][j] = delta;
        health += delta;
        
        return memo[i][j][health] = false;
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size(), m = grid[0].size();
        memset(memo, -1, sizeof memo);
        return dfs(grid, 0, 0, health);
    }
};