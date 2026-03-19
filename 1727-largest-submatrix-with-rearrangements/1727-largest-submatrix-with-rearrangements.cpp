class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Build heights
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] != 0 && row > 0) {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
        }

        vector<vector<int>> grid = matrix;

        // Sort each row
        for (int i = 0; i < m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n;j++) {
                int x = grid[i][j];

                    int idx = grid[i].size() -j;
                              

                    ans = max(ans, idx *x);
                }
            }
             return ans;
        }

       
    };