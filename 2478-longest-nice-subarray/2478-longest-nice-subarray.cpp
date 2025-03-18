class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, maxSize = 0;  // Initial max size should be 0, not INT_MIN
        vector<int> bitset(32, 0);
        
        while (r < n) {
            bool conflict = false;
            
            // Check for conflicts with existing bits
            for (int i = 0; i < 32; i++) {
                if ((1 << i) & nums[r]) {
                    if (bitset[i] == 1) {
                        conflict = true;
                        break;
                    }
                }
            }
            
            if (conflict) {
                // If conflict, update max and move left pointer
                maxSize = max(maxSize, r - l);
                
                // Reset bitset and move left pointer until conflict is resolved
                while (l < r) {
                    // Remove bits of nums[l] from bitset
                    for (int i = 0; i < 32; i++) {
                        if ((1 << i) & nums[l]) {
                            bitset[i]--;
                        }
                    }
                    l++;
                    
                    // Check if conflict is resolved
                    bool stillConflict = false;
                    for (int i = 0; i < 32; i++) {
                        if ((1 << i) & nums[r] && bitset[i] == 1) {
                            stillConflict = true;
                            break;
                        }
                    }
                    
                    if (!stillConflict) break;
                }
            }
            
            // Add current number's bits to bitset
            for (int i = 0; i < 32; i++) {
                if ((1 << i) & nums[r]) {
                    bitset[i]++;
                }
            }
            
            r++;
        }
        
        // Don't forget to update max size at the end
        maxSize = max(maxSize, r - l);
        
        return maxSize;
    }
};