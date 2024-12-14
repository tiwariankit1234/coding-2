class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort based on the end points of the balloons
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Track the position of the previous arrow
        int prev = points[0][1];
        int count = 1; // At least one arrow is needed

        // Iterate through the points
        for (const auto& it : points) {
            // If the start of the current balloon is beyond the previous arrow
            if (it[0] > prev) {
                count++;
                prev = it[1]; // Update the position of the arrow
            }
        }

        return count;
    }
};
