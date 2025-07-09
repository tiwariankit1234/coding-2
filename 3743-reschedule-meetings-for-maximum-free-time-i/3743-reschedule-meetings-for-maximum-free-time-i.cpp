class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& start, vector<int>& end) {
        vector<vector<int>> temp;
        int n = start.size();
         temp.push_back({0,0});
        // Build the temp array of events
        for (int i = 0; i < n; ++i) {
            temp.push_back({start[i], end[i]});
        }

        // Add dummy event at eventTime to capture free time after last event
        temp.push_back({eventTime, eventTime});
        n = temp.size();

        int freetime = temp[0][0];  // time before first event starts
        int maxTime = freetime;

        int l = 0, r = 0;

        while (r < n) {
            // Add free time between r-th and r+1-th event
            if (r + 1 < n) {
                freetime += temp[r + 1][0] - temp[r][1];
            } else {
                // At last dummy event: no additional gap
            }

            // Maintain window size of k events
            if (r - l + 1 == k+1) {
                maxTime = max(maxTime, freetime);

                // Remove leftmost gap from freetime
                if (l + 1 < n) {
                    freetime -= temp[l + 1][0] - temp[l][1];
                }
                l++;
            }

            r++;
        }

        return maxTime;
    }
};
