class Solution {
public:


    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m; // Frequency map

        // Count frequency of each number
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        vector<pair<int, int>> v; // Vector to store {frequency, number}

        // Transfer data from map to vector
        for (auto &it : m) {
            v.push_back({it.second, it.first});
        }

        // Sort using the custom comparator
        sort(v.begin(), v.end(), [](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first)
            return a.second>b.second;
            return a.first<b.first;
        });

        vector<int> ans; // Final sorted result

        // Construct the sorted array
        for (int i = 0; i < v.size(); i++) {
            int k = v[i].first;
            while (k--) {
                ans.push_back(v[i].second);
            }
        }

        return ans;
    }
};