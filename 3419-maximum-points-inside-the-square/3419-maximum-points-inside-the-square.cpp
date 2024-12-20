class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string l) {
        int low = 0, high = 2*1e9, ans = 0;

        // Function to check if a square of side `side` can include distinct points
        auto possible = [&](int side) {
            int n = points.size();
            set<char> seen;
            int count = 0;
            int half_side = side / 2;

            for (int i = 0; i < n; i++) {
                int x = points[i][0], y = points[i][1];
                if (abs(x) <= half_side && abs(y) <= half_side) {
                    if (seen.find(l[i]) == seen.end()) {
                        seen.insert(l[i]);
                        count++;
                    } else {
                        return false; // Duplicate character found
                    }
                }
            }

            return true; // Return true if at least one valid point exists
        };

        // Binary search to find the maximum square side
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (possible(mid)) {
                cout<<mid<<" "<<ans<<endl;
                ans = mid;  // Update the answer if possible
                low = mid + 1; // Try for a larger side
            } else {
                high = mid - 1; // Decrease the side
            }
        }
            

            set<char> seen;
            int count = 0;
            int half_side = ans / 2;
             int n = points.size();


            for (int i = 0; i < n; i++) {
                int x = points[i][0], y = points[i][1];
                if (abs(x) <= half_side && abs(y) <= half_side) {
                    if (seen.find(l[i]) == seen.end()) {
                        seen.insert(l[i]);
                        count++;
                    } else {
                        return false; // Duplicate character found
                    }
                }
            }

            return count;


        // return ans; // Return the largest valid side found
    }
};
