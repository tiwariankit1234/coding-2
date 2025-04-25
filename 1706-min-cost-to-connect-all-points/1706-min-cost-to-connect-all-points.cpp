class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> inMST(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        // priority_queue stores: {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});

        int totalCost = 0;

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            totalCost += cost;

            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (wt < minDist[v]) {
                        minDist[v] = wt;
                        pq.push({wt, v});
                    }
                }
            }
        }

        return totalCost;
    }
};
