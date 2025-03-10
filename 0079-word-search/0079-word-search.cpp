class Solution {
public:
    bool f(int i, int j, int index, string &word, vector<vector<bool>> &visited, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // If we've matched all characters in the word
        if (index == word.size()) {
            return true;
        }
        
        // Out of bounds or already visited or character doesn't match
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] != word[index]) {
            return false;
        }
        
        // Mark as visited
        visited[i][j] = true;
        
        // Try all four directions
        bool found = f(i+1, j, index+1, word, visited, grid) || 
                     f(i, j+1, index+1, word, visited, grid) ||
                     f(i-1, j, index+1, word, visited, grid) ||
                     f(i, j-1, index+1, word, visited, grid);
        
        // Backtrack
        visited[i][j] = false;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& grid, string word) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Try starting from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == word[0] && f(i, j, 0, word, visited, grid)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};