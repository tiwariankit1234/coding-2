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
bool f(TreeNode *root,TreeNode *subRoot){
    if(!root and !subRoot)return true;
    if(!root and subRoot)return false;
    if(root and !subRoot)return false;
    if(root->val!=subRoot->val)return false;
    return f(root->left,subRoot->left) and f(root->right,subRoot->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
         if(!root and !subRoot)return true;
    if(!root and subRoot)return false;
    if(root and !subRoot)return false;
    
        if(root->val==subRoot->val){
            ans=ans||(f(root->left,subRoot->left) and (f(root->right,subRoot->right)));
            if(ans==true)return ans;
        }
       ans=ans||isSubtree(root->left,subRoot);
       if(ans==true)return ans;
       ans=ans||isSubtree(root->right,subRoot);
       if(ans==true)return ans;
       return ans;
    }
};