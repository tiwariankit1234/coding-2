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
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if(root==NULL)return NULL;
      
       
//      TreeNode* left=searchBST(root->left,val);
//         if(root->val==val)return root;
//         if(left)return left;
       
//       TreeNode* right=searchBST(root->right,val);
//        if(right)
//        return right;
     
//      return NULL;
//     }
// };


// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if(root==NULL || root->val==val)return root;
      
//        return root->val>val? searchBST(root->left,val):searchBST(root->right,val);

//     }
    
// };

class Solution {
    public:
    TreeNode* searchBST(TreeNode* root,int val){

        while(root!=NULL and root->val!=val){
           if(val<root->val){
            root=root->left;
           }
           else{
            root=root->right;
           }
        }
    
    return root;
}
};

