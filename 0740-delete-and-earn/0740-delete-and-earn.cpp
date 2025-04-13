class Solution {
public:
    // Use memoization to avoid recomputing subproblems
    int f(int idx, vector<int>& nums, unordered_map<int, int>& mp, vector<int>& memo) {
        int n = nums.size();
        
        // Base case
        if (idx >= n) return 0;
        
        // If already computed
        if (memo[idx] != -1) return memo[idx];
        
        // Take current element
        int take = mp[nums[idx]] * nums[idx];
        
        // Skip all elements with the same value or value+1
        int nextIdx = idx + 1;
        while (nextIdx < n && (nums[nextIdx] == nums[idx] || nums[nextIdx] == nums[idx] + 1)) {
            nextIdx++;
        }
        
        take += f(nextIdx, nums, mp, memo);
        
        // Don't take current element
        int notake = f(idx + 1, nums, mp, memo);
        
        // Store and return the maximum
        return memo[idx] = max(take, notake);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        // Count frequencies of each number
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        
        // Remove duplicates and sort
        sort(nums.begin(), nums.end());
       
   

        cout<<endl;
        // Initialize memoization array
        vector<int> memo(nums.size(), -1);
        
        return f(0, nums, mp, memo);
    }
};