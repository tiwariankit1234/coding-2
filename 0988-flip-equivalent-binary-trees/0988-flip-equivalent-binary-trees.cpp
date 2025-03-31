/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool f(TreeNode* root1,TreeNode* root2){
  if(!root1 and !root2)return true;
  if(root1 and !root2 ||root2 and !root1)return false;


  if(root1->val!=root2->val)return false;

  bool t=f(root1->left,root2->left) and f(root1->right,root2->right);
  bool k=f(root1->left,root2->right) and f(root1->right,root2->left);
  return t||k;
}
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return f(root1,root2);
    }
};