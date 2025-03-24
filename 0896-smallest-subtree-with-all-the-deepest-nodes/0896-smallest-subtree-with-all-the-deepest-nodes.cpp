class Solution{
 public:
int depth(TreeNode *root) {
    return !root ? 0 : max(depth(root->left), depth(root->right)) + 1;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int d = depth(root->left) - depth(root->right);
    if(d==0){
         return root;
    }
    else if(d>0){
        return subtreeWithAllDeepest(root->left);
    }
    else{
        return  subtreeWithAllDeepest(root->right);
    } 

}
};