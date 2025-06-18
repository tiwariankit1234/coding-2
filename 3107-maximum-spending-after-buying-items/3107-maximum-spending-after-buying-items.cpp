#define ll long long
class Solution {
public:
    int f(vector<vector<int>>& grid) {
        int m = grid.size();
        int minirow = -1;
        int ans = INT_MAX;

        for (int i = 0; i < m; i++) {
            if (!grid[i].empty()) {
                int back = grid[i].back();
                if (back < ans) {
                    ans = back;
                    minirow = i;
                }
            }
        }

        if (minirow != -1) {
            grid[minirow].pop_back();
        }

        return ans;
    }

    long long maxSpending(vector<vector<int>>& values) {
        ll m = values.size(), n = values[0].size();
        ll totalcost = 0;
        for (ll day = 1; day <= m * n; day++) {
            ll val = f(values);
            totalcost += day * val;
        }
        return totalcost;
    }
};
