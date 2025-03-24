class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return f(root, limit, 0) ? root : nullptr;
    }
    
private:
    bool f(TreeNode* root, int limit, int sum) {
        // Base case: if root is null, return false
        if (!root) return false;
        
        // Update current path sum
        sum += root->val;
        
        // If it's a leaf node, check if path sum meets the limit
        if (!root->left && !root->right) {
            return sum >= limit;
        }
        
        // Recursively check left and right subtrees
        bool leftExists = root->left && f(root->left, limit, sum);
        bool rightExists = root->right && f(root->right, limit, sum);
        
        // Remove subtrees that don't meet the limit
        if (!leftExists) root->left = nullptr;
        if (!rightExists) root->right = nullptr;
        
        // Return true if either subtree exists
        return leftExists || rightExists;
    }
};