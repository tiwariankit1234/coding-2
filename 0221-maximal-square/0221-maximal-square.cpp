class Solution {
public:

    int largestSquareArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        // Calculate previous smaller elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for next smaller elements
        while (!st.empty()) st.pop();

        // Calculate next smaller elements
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxSide = 0;

        // Calculate max square side length
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int side = min(height, width);
            maxSide = max(maxSide, side);
        }

        // Return the area of the largest square
        return maxSide * maxSide;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));

        // Build height matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = (i == 0) ? 1 : heights[i - 1][j] + 1;
                }
            }
        }

        int maxSquareArea = 0;

        // Calculate max square area row by row
        for (int i = 0; i < m; i++) {
            maxSquareArea = max(maxSquareArea, largestSquareArea(heights[i]));
        }

        return maxSquareArea;
    }
};
