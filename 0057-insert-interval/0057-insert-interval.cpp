class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& temp) {
        arr.push_back(temp);
        sort(arr.begin(), arr.end());  // sort by start

        vector<vector<int>> ans;
        for (auto &interval : arr) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                // no overlap
                ans.push_back(interval);
            } else {
                // overlap → merge
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};
