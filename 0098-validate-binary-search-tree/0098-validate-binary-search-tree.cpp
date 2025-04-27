class Solution {
public:

    #define ll long long
    ll ans = 1;
    pair<ll, ll> f(TreeNode* root) {
       if (!root) return {LLONG_MAX, LLONG_MIN};
// For empty subtree
        
        auto left = f(root->left);
        auto right = f(root->right);
        ll left_max = left.second;
        ll right_min = right.first;
        
        if (left_max >= root->val || right_min <= root->val) {
            ans = 0;
            return {LLONG_MAX,LLONG_MIN}; // return invalid range
        }
        ll subtree_min = min((ll)root->val, left.first);ll subtree_max = max((ll)root->val, right.second);
        
        return {subtree_min, subtree_max};
    }
    
    bool isValidBST(TreeNode* root) {
        f(root);
        return ans;
    }
};
