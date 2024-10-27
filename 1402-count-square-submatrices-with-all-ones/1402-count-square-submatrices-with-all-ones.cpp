class Solution {
public:
    int check(const vector<vector<int>>& arr, int steps, int m, int n) {
        int uppercount = 0;
        
        // Loop over each possible top-left position for a square of size `steps x steps`
        for (int i = 0; i <= m - steps; i++) {
            for (int j = 0; j <= n - steps; j++) {
                bool isSquare = true;

                // Check if the square of size `steps x steps` starting at (i, j) is all 1s
                for (int x = i; x < i + steps; x++) {
                    for (int y = j; y < j + steps; y++) {
                        if (arr[x][y] != 1) {
                            isSquare = false;
                            break;
                        }
                    }
                    if (!isSquare) break;
                }

                // Increment count if a valid square was found
                if (isSquare) uppercount++;
            }
        }
        
        return uppercount;
    }

    int countSquares(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        int maxSteps = min(m, n);  // Maximum size for square submatrices
        int count = 0;
        
        // Check for all squares of size 1x1, 2x2, ..., up to maxSteps x maxSteps
        for (int steps = 1; steps <= maxSteps; steps++) {
            count += check(arr, steps, m, n);
        }
        
        return count;
    }
};
