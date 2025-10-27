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
int f(TreeNode* root,int &k,int &ans){
    if(!root)return 0;
    f(root->left,k,ans);
    k--;
    if(k==0){
        ans=root->val;
    }
    f(root->right,k,ans);
    return 0;

}
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        f(root,k,ans);
        return ans;
    }
};