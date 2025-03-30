
class Solution {
public:
// function return the trim binary search tree
 TreeNode* f(TreeNode* root,int low,int high){
    if(!root)return NULL;
      if(root->val<low){
       return  f(root->right,low,high);
        
      }
        else if(root->val>high){
            return f(root->left,low,high);
               
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