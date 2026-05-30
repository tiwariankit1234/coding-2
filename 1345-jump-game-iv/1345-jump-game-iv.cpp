class Solution {
public:
    int shortestDistance(int n, vector<vector<int>>& adj, int src, int dest,
                         unordered_map<int,vector<int>>& mp,vector<int>&nums) {

        vector<int> vis(n, 0);
        queue<pair<int, int>> q; // {node, distance}

        q.push({src, 0});
        vis[src] = 1;

        while (!q.empty()) {

            auto [node, dist] = q.front();
            q.pop();

            if (node == dest)
                return dist;

            for (int nei : mp[nums[node]]) {

                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push({nei, dist + 1});
                }
            }
            mp[nums[node]].clear();
            mp.erase(nums[node]);
            if (node - 1 >= 0 and vis[node - 1] == 0) {
                vis[node - 1] = 1;
                q.push({node - 1, dist + 1});
            }
            if (node + 1 <= (n - 1) and vis[node + 1] == 0) {
                vis[node+1]=1;
                q.push({node + 1, dist + 1});
            }
        }

        return -1; // destination not reachable
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        cout << n << endl;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 <= (n - 1)) {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                mp[nums[i]].push_back(i);
            } else if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]].push_back(i);
            }
        }

        int ans = n - 1;
        ans = min(ans, shortestDistance(n, adj, 0, n - 1, mp,nums));

        return ans;
    }
};