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
int f(TreeNode*root){
    int lh=0,rh=0;
     TreeNode* l=root;
     TreeNode* r=root;
     while(l){
        l=l->left;
        lh++;
     }
     while(r){
        r=r->right;
        rh++;
     }
     if(lh==rh)return (1<<lh)-1;
    
    return 1+f(root->left)+f(root->right);
}
    int countNodes(TreeNode* root) {
        return f(root);
    }
};