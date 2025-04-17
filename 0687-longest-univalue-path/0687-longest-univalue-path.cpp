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
int maxpath=0;
int f(TreeNode* root,TreeNode* parent){
    if(!root)return 0;
    
    int left=f(root->left,root);
    int right=f(root->right,root);
    // cout<<root->val<<" "<<left<<" "<<right<<endl;
    maxpath=max(maxpath,left+right);
    if(root->val!=parent->val)return 0;
    return max(left+1,right+1);
}
    int longestUnivaluePath(TreeNode* root) {
       f(root,root);
       return maxpath;
    }
};