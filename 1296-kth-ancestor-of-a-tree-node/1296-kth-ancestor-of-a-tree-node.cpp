class TreeAncestor {
public:
    vector<vector<int>> dp; // Binary lifting table
    int LOG;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = log2(n) + 1; // Max power of 2 needed
        dp.resize(n, vector<int>(LOG, -1)); // dp[i][j] stores 2^j-th ancestor of node i

        // Initialize first ancestor (direct parent)
        for (int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
        }

        // Fill DP table for 2^j ancestors
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int prevAncestor = dp[i][j - 1]; // 2^(j-1) ancestor
                if (prevAncestor != -1) {
                    dp[i][j] = dp[prevAncestor][j - 1]; // Jump another 2^(j-1)
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) { // If the j-th bit is set in k
                node = dp[node][j]; // Jump 2^j steps up
                if (node == -1) return -1; // If ancestor doesn't exist
            }
        }
        return node;
    }
};
