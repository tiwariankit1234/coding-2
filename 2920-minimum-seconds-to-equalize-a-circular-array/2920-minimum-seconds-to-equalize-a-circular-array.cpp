class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> indexes;
        
        int n = nums.size();
        int min_dist = n-1;
        
        for (int j = 0; j < n; j ++) 
            indexes[nums[j]].push_back(j);
        
        for (auto i : indexes) {
            vector<int> pos = i.second;
            
            int len = pos.size();
            int max_dist = (n - 1 - pos[len-1]) + pos[0];
            
            for (int j = 1; j < len; j ++) {
                max_dist = max (max_dist, pos[j] - pos[j-1] - 1);
            }
            
            min_dist = min(min_dist, (max_dist+1)/2);
        }
        
        return (min_dist) ;
    }
};