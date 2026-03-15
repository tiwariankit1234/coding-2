class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        
        // Safety check to prevent out-of-bounds on tiny arrays
        if (n <= 3) return n; 
        
        int ans = 2;
        vector<int> prefix(n, 2), suffix(n, 2);
        prefix[0] = 1; 
        suffix[n - 1] = 1;
        
        // 1. Build Prefix Array
        for (int i = 2; i < n; i++) {
            if ((nums[i] + nums[i - 2]) == 2 * nums[i - 1]) {
                prefix[i] = prefix[i - 1] + 1;
                ans = max(ans, prefix[i]);
            }
        }
        
        // 2. Build Suffix Array
        for (int i = n - 3; i >= 0; i--) {
            if ((nums[i] + nums[i + 2]) == 2 * nums[i + 1]) {
                suffix[i] = suffix[i + 1] + 1;
                ans = max(ans, suffix[i]);
            }
        }
        
        // 3. Check extending ANY prefix or suffix by 1 element
        // (Moved out of the 'else' block so it safely checks every element)
        for (int i = 1; i < n; i++) {
            ans = max(ans, prefix[i - 1] + 1);
        }
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, suffix[i + 1] + 1);
        }
        
        // 4. Bridging Logic
        for (int i = 1; i < n - 1; i++) {
            // Check if we can form a local bridge between i-1 and i+1
            if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {
                int d = (nums[i + 1] - nums[i - 1]) / 2;
                
                // Base bridge length is 3 (nums[i-1], the new modified nums[i], and nums[i+1])
                int current_len = 3; 
                
                // INDEPENDENTLY check if the left side matches our difference
                if (i >= 2 && (nums[i - 1] - nums[i - 2] == d)) {
                    // Add the left prefix (subtract 1 because nums[i-1] is already counted)
                    current_len += (prefix[i - 1] - 1); 
                }
                
                // INDEPENDENTLY check if the right side matches our difference
                if (i + 2 < n && (nums[i + 2] - nums[i + 1] == d)) {
                    // Add the right suffix (subtract 1 because nums[i+1] is already counted)
                    current_len += (suffix[i + 1] - 1); 
                }
                
                ans = max(ans, current_len);
            }
        }
        
        // Cap the answer at 'n' in case overlapping logic pushes it over
        return min(ans, n);
    }
};