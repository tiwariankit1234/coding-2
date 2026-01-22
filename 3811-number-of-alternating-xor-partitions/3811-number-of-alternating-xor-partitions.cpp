#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    // Memoization table: memo[i][t]
    // i: current index
    // t: current target needed (0 for Target2, 1 for Target1)
    int memo[100005][2];
    
    // Arrays to store the nearest next jump indices
    vector<int> nxt0, nxtT1, nxtT2;
    int n;

    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        n = nums.size();
        
        // Initialize next jump arrays
        nxt0.assign(n, -1);
        nxtT1.assign(n, -1);
        nxtT2.assign(n, -1);

        // Precompute next indices using a hash map
        // map stores: value -> nearest index found so far (scanning backwards)
        unordered_map<int, int> pos;
        pos.reserve(n * 2);
        
        int xr = 0;
        pos[0] = n; // Base case: sum of full suffix is 0 relative to end

        for(int i = n - 1; i >= 0; --i) {
            xr ^= nums[i];

            // If we want sub-segment sum == T, we need Suffix[j] == Suffix[i] ^ T
            if (pos.count(xr)) nxt0[i] = pos[xr];
            if (pos.count(xr ^ target1)) nxtT1[i] = pos[xr ^ target1];
            if (pos.count(xr ^ target2)) nxtT2[i] = pos[xr ^ target2];

            pos[xr] = i;
        }

        // Initialize memoization table with -1
        for(int i = 0; i <= n; i++) {
            memo[i][0] = -1;
            memo[i][1] = -1;
        }

        // --- Logic for the First Step ---
        // The sequence MUST start with Target 1. Zeros are not allowed *before* the first Target 1.
        // So we strictly look for the first Target 1 jump from index 0.
        
        int firstJumpIndex = nxtT1[0];
        
        // If we can't even make the first Target 1 segment, return 0
        if (firstJumpIndex == -1) return 0;

        // Start recursion from the index after the first block.
        // We just completed Target 1, so the next target needed is Target 2 (param 0).
        return solve(firstJumpIndex, 0);
    }

    // Recursive function
    // i: current index
    // t: 1 if we need Target 1 next, 0 if we need Target 2 next
    int solve(int i, int t) {
        // Base Case: Successfully reached the end
        if (i == n) return 1;
        
        // Return cached result
        if (memo[i][t] != -1) return memo[i][t];

        long long ans = 0;

        // Option 1: Find the Required Target (T1 or T2)
        // If t==1, look for T1 jump. If t==0, look for T2 jump.
        int targetJump = (t == 1) ? nxtT1[i] : nxtT2[i];
        
        if (targetJump != -1) {
            // If found, jump there and flip the target requirement (t ^ 1)
            ans = (ans + solve(targetJump, t ^ 1)) % MOD;
        }

        // Option 2: Find a Zero Segment
        // Zero segments are always allowed after the sequence has started.
        // Jumping over a zero segment DOES NOT change the target requirement `t`.
        int zeroJump = nxt0[i];
        
        if (zeroJump != -1) {
            ans = (ans + solve(zeroJump, t)) % MOD;
        }

        return memo[i][t] = (int)ans;
    }
};