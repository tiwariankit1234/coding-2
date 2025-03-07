class Solution {
public:
    vector<vector<int>> output;
    int n;
    void backtrack(int first, vector<int> &curr, vector<int>& nums) {
        // if the combination is done
           output.push_back(curr);
        
        for (int i = first; i < n; ++i) {
            // add i into the current combination
            curr.push_back(nums[i]);
            
            // use next integers to complete the combination
            backtrack(i + 1, curr, nums);
            // backtrack
            curr.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
            backtrack(0, curr, nums);
        
        return output;
    }
};