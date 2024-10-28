#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int maxArea = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Iterate over all possible top-left corners
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Only start if the cell contains '1'
                if (matrix[i][j] == '1') {
                    // Expand the rectangle from (i, j) as the top-left corner
                    int minWidth = cols;

                    // Try to find the maximum rectangle starting from (i, j)
                    for (int k = i; k < rows; k++) {
                        if (matrix[k][j] == '0') break; // If we encounter a '0', stop expanding

                        // Update the minimum width for the current row
                        int width = 0;
                        while (width + j < cols && matrix[k][j + width] == '1') {
                            width++;
                        }
                        minWidth = min(minWidth, width);

                        // Calculate area of the rectangle with top-left (i, j) and bottom-right (k, j + minWidth - 1)
                        int area = minWidth * (k - i + 1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }

        return maxArea;
    }
};
