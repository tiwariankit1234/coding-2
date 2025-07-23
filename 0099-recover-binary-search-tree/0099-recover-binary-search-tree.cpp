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
TreeNode* prev=NULL;
TreeNode* first;
TreeNode* second; 
bool flag=false;
void f(TreeNode *root,TreeNode* &prev){
    if(root==NULL)return;
    f(root->left,prev);
     if(flag==false and prev!=NULL and prev->val>root->val){
        first=prev;
        flag=true;
     }
     if(flag and prev!=NULL and prev->val>root->val){
        second=root;
     }
    prev=root;
    f(root->right,prev);
}
    void recoverTree(TreeNode* root) {
      f(root,prev);
    //   cout<<first->val<<" "<<second->val<<endl;
      swap(first->val,second->val);
      return ;
    }
};