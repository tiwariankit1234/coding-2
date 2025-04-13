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
int f(TreeNode* root,int& maxsum){
    if(!root)return 0;
    auto lefty=f(root->left,maxsum);
    if(lefty<0)lefty=0;
    auto righty=f(root->right,maxsum);
    if(righty<0)righty=0;
    maxsum=max(root->val+lefty+righty,maxsum);
    return max(root->val+lefty,root->val+righty);
}
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        f(root,maxsum);
        return maxsum;
    }
};