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
 #define ll long long 
class Solution {
public:
   int count=0;
   int f(TreeNode* root,ll k){
     if(!root)return 0;
   
     if(root->val==k){
        count++;
      
     }

   

    return f(root->left,k-root->val)+f(root->right,k-root->val);
   }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;

        f(root,targetSum);

        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
        
    }
};