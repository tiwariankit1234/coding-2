/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
        
        int maxD=0;
    int maxDiameter(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = levels(root->left);
        int rightHeight = levels(root->right);
        int diameter = leftHeight+rightHeight;
        maxD = max(maxD, diameter);
        maxDiameter(root->left);
        maxDiameter(root->right);
        return 5;
    }

    int diameterOfBinaryTree(TreeNode* root) {
     
 maxDiameter(root);
 return maxD;
    
    }
};
