#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items based on the price
        sort(items.begin(), items.end());
        
        // Create a vector to store the maximum beauty for each item
        int k = items.size();
        vector<int> ans(queries.size(), 0);
        vector<int> maxBeauty(k, 0);
        
        // Update the beauty for each item, ensuring it holds the max beauty up to that point
        int maxbeauty = 0;
        for (int i = 0; i < k; i++) {
            maxbeauty = max(maxbeauty, items[i][1]);
            maxBeauty[i] = maxbeauty;  // Store the max beauty encountered so far
        }
        
        // Iterate over each query and find the corresponding maximum beauty
        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            // Find the first item whose price is greater than or equal to the query
            auto it = upper_bound(items.begin(), items.end(), vector<int>{query, INT_MAX});
            
            if (it == items.begin()) {
                ans[i] = 0;  // No items available for this price range
            } else {
                int index = it - items.begin() - 1;  // Get the index of the last item within budget
                ans[i] = maxBeauty[index];  // Get the maximum beauty of found item
            }
        }
        
        return ans;
    }
};