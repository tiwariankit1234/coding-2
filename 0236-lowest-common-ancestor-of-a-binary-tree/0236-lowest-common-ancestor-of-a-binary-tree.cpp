/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
TreeNode* f(TreeNode* root,TreeNode* p,TreeNode* q){
   if(!root ||root==p ||root==q)return root;
    TreeNode* left=f(root->left,p,q);
    TreeNode* right=f(root->right,p,q);
    if(left and right)return root;
    return left?left:right;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};