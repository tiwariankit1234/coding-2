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
   int sum;
   void f(TreeNode* root,string s){
    if(!root)return ;
    // cout<<root->val<<" ";
    // for(auto it:s){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    if(!root->left and !root->right){
        s.push_back((char)(root->val+'0'));
        int k=s.size();
        for(int i=0;i<k;i++){
            if(s[i]=='1'){
                sum+=(1<<(k-1-i));
            }
        }
    }
    s.push_back((char)(root->val+'0'));
    f(root->left,s);
    f(root->right,s);
    return ;
   }
    int sumRootToLeaf(TreeNode* root) {
        string s="";
        sum=0;
         f(root,s);
         return sum;
    }
};