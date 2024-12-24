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
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
         int leftheight=height(root->left);
         int rightheight=height(root->right);
         maxD=max(leftheight+rightheight,maxD);
         return max(leftheight,rightheight)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
     
         height(root);
         return maxD;
    
    }
};
