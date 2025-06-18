#define ll long long

class Solution {
public:
    int f(vector<vector<int>>& grid) {
        int m = grid.size();
        int minirow = -1;
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            if(!grid[i].empty()){
            
                if (grid[i].back() < ans) {
                     ans=grid[i].back();
                     minirow=i;
                }
            }
        }
        
        grid[minirow].pop_back();
        return ans;
    }

    long long maxSpending(vector<vector<int>>& values) {
        ll m = values.size(), n = values[0].size();
        ll totaldays = m * n;
        ll totalcost = 0;
        for (ll i = 1; i <= m * n; i++) {
            ll minimumelement = f(values);
            totalcost += i * minimumelement;
        }
        return totalcost;
    }
};