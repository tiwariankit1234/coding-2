#define ll long long
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
ll k=1e9+7;
ll f1(TreeNode* root){
    if(!root)return 0;
    ll sum=0;
    sum=root->val+f1(root->left)+f1(root->right);
    return sum;
}
ll f2(TreeNode*root,ll &ans,ll totalsum){
    if(!root->left and !root->right)return root->val;
     ll leftsum=0;
    if(root->left){
       leftsum=f2(root->left,ans,totalsum);
       ll x=(totalsum-leftsum)*leftsum;
        
       ans=max(ans,x);
    }
    ll rightsum=0;
    if(root->right){
      rightsum=f2(root->right,ans,totalsum);
      ll x=(totalsum-rightsum)*rightsum;
      ans=max(ans,x);
    }
    return root->val+leftsum+rightsum;
}
    int maxProduct(TreeNode* root) {
        ll ans=LLONG_MIN;
        ll totalsum=0;
        totalsum=f1(root);
       f2(root,ans,totalsum);
       ans=ans%k;
       return (int)ans;
    }
};