
class Solution {
public:
int sum=0;
int f(TreeNode* root){
    if(!root)return 0;

    sum=root->val+f(root->left)+f(root->right);
    return sum;
}
   TreeNode* inorder(TreeNode* root){
    if(!root)return NULL;
    inorder(root->left);
    int previous=root->val;
    root->val=sum;
  
    sum=sum-previous;
   
    inorder(root->right);
    return root;

   }
    TreeNode* convertBST(TreeNode* root) {
        sum=f(root);
        
        return inorder(root);
    }
};