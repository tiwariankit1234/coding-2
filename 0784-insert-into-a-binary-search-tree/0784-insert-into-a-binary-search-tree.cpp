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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        TreeNode* prevNode=NULL;
        TreeNode *curr=root;
        while(root){
            if(root->val>val){
                prevNode=root;
                root=root->left;
            }
            else{
                prevNode=root;
                root=root->right;
            }
        }
        
        if(prevNode->val>val){
            prevNode->left=new TreeNode(val);
        }
        else{
            prevNode->right=new TreeNode(val);
        }
        return curr;
    }
};