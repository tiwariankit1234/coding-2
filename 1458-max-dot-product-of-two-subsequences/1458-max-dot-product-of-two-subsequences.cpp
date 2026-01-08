class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        const int NEG_INF = -1e8;

        vector<int> next(n2 + 1, NEG_INF), cur(n2 + 1, NEG_INF);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int take = nums1[i] * nums2[j];
                take = max(take, take + next[j + 1]);

                int skip1 = next[j];
                int skip2 = cur[j + 1];

                cur[j] = max({take, skip1, skip2});
            }
            next = cur;  // roll rows
        }

        return next[0];
    }
};
