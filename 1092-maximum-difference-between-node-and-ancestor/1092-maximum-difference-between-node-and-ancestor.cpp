
class Solution {
public:
int ans=INT_MIN;
void f(TreeNode* root,int currentvalue){
    if(!root)return ;
          ans=max(ans,abs(currentvalue-root->val));;
          f(root->left,currentvalue);
          f(root->right,currentvalue);
          return ;
}
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return 0;
        if(!root->left and !root->right)return 0;
        f(root,root->val);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return ans;
    }
};