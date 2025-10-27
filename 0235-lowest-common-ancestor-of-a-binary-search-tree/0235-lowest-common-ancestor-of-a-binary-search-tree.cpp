/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root|| p->val==root->val || q->val==root->val)return root;
         TreeNode *left=NULL;
         TreeNode* right=NULL;
        if((p->val<root->val )and (root->val<q->val)||(p->val>root->val )and (root->val>q->val))return root;
        else if(root->val>p->val and root->val>q->val){left= lowestCommonAncestor(root->left,p,q);
        }
        else{
       right=lowestCommonAncestor(root->right,p,q);
        }
        if(left and right)return root;
        if(left )return left;
        if(right)return right;
        return NULL;
    }
};