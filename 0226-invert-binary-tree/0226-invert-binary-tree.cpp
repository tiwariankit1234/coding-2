//https://leetcode.com/problems/invert-binary-tree/
class Solution {
public:
void helper(TreeNode* root){
    if(root==NULL)return;
     swap(root->left,root->right);
    helper(root->left);
    helper(root->right);
   
    return ;
}
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        helper(root);
        return root;
    }
};