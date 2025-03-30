
class Solution {
public:
// function return the trim binary search tree
 TreeNode* f(TreeNode* root,int low,int high){
      if(root->val<low){
        if(root->right)return  f(root->right,low,high);
        else{
            return NULL;
        }
      }
        else if(root->val>high){
            if(root->left)return f(root->left,low,high);
            return NULL;
        }
       else{
         if(root->left)root->left=f(root->left,low,high);
         if(root->right)root->right=f(root->right,low,high);
         return root;
       }
       return root;
      }
 
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return f(root,low,high);
    }
};