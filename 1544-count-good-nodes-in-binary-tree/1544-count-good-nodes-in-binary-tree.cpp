
class Solution {
public:
int count=0;
void f(TreeNode* root,int maxvalue){

    if(!root)return ;
    if(root->val>=maxvalue){
        count++;
      maxvalue=root->val;
    }
    if(root->left)f(root->left,maxvalue);
    if(root->right)f(root->right,maxvalue);
    return ;
}

    int goodNodes(TreeNode* root) {
         f(root,INT_MIN);
         return count;
    }
};