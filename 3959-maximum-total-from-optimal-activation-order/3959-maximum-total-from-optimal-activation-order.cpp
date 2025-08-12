#define ll long long
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        vector<pair<int, int>> tasks(n);

        // Pair each (limit, value)
        for (int i = 0; i < n; i++) {
            tasks[i] = {limit[i], value[i]};
        }

        // Sort: smaller limit first, and for equal limit, higher value first
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });

        ll gain = 0;
        int active = 0, i = 0, l = 0;

        while (i < n && l < n) {
            // Try to take this task if active < limit
            if (active < tasks[i].first) {
                gain += tasks[i].second;
                active++;
            }

            // Remove expired tasks
            int x=0;
            while (l < n && tasks[l].first <= active) {
               x++;
                l++;
            }
            active-=x;
            if (active < 0) active = 0;

            // Move forward
            i = max(i + 1, l);
        }

        return gain;
    }
};
