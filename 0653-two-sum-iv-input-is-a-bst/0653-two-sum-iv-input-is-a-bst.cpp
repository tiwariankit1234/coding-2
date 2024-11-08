
class Solution {
public:
  unordered_set<int>s;
    bool findTarget(TreeNode* root, int k) {
       if(!root)return false;
       bool left= findTarget(root->left,k);
       if(!s.count(k-root->val)) s.insert(root->val);
       else
       return true;
       bool right=findTarget(root->right,k);
       return left||right;
       
        
    }
};