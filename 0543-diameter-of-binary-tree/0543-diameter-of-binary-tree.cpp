

class Solution {
public:
   int f(TreeNode* root,int& maxdiameter){
    if(!root)return 0;
    int left=f(root->left,maxdiameter);
    int right=f(root->right,maxdiameter);
    maxdiameter=max(maxdiameter,left+right);
    return 1+max(left,right);
   }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdiameter=INT_MIN;
      f(root,maxdiameter);
      return maxdiameter;
    }
};