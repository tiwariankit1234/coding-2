
class Solution {
public:

int f(TreeNode* root,int maxvalue){

    if(!root)return 0;
    int count=0;
    if(root->val>=maxvalue){
        count++;
      maxvalue=root->val;
    }
    if(root->left)count+=f(root->left,maxvalue);
    if(root->right)count+=f(root->right,maxvalue);
    return count;
}

    int goodNodes(TreeNode* root) {
         return f(root,INT_MIN);
     
    }
};