
class Solution {
public:
bool f(TreeNode* p,TreeNode* q){
    if(p and !q)return false;
    if(!p and !q)return true;
    if(!p and q)return false;
    if(p->val!=q->val)return false;
    return f(p->right,q->left) and f(p->left,q->right);
}
    bool isSymmetric(TreeNode* root) {
        return f(root->left,root->right);
    }
};