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
 unordered_map<int,int>mp;
class Solution {
public:

bool f(TreeNode* root,int k,unordered_map<int,int>&mp){
     if(!root)return false;
         cout<<root->val<<endl;
        bool left=f(root->left,k,mp);
        if(mp.find(k-root->val)!=mp.end()){
            return true;
        }
        mp[root->val]++;
        bool right=f(root->right,k,mp);
        cout<<left<<" "<<right<<endl;
        return left||right;
}
    bool findTarget(TreeNode* root, int k) {
       
       unordered_map<int,int>mp;
       return f(root,k,mp);
    }
};