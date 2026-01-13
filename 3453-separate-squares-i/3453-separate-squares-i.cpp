class Solution {
public:
    bool check(long double acy, vector<vector<int>>& squares) {
        long double below = 0.0L, above = 0.0L;

        for (auto &it : squares) {
            long double y = it[1];
            long double side = it[2];
            long double total = side * side;

            if (y + side <= acy) {
                below += total;
            } 
            else if (y >= acy) {
                above += total;
            } 
            else {
                below += (acy - y) * side;
                above += (y + side - acy) * side;
            }
        }
        return above <= below;   // monotonic condition ✅
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double l = 1e18, h = -1e18;

        for (auto &s : squares) {
            l = min(l, (long double)s[1]);
            h = max(h, (long double)(s[1] + s[2]));
        }

        // fixed iterations (more stable than while(h-l>eps))
        for (int iter = 0; iter < 80; iter++) {
            long double mid = (l + h) / 2.0L;
            if (check(mid, squares)) h = mid;
            else l = mid;
        }

        return (double)h;
    }
};
