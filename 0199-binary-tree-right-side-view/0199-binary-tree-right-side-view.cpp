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
void f(TreeNode* root,int x,int y,map<int,int>&mp){
       if(!root)return ;
    mp[y]=root->val;
    f(root->left,x-1,y+1,mp);
    f(root->right,x+1,y+1,mp);
    return ;
}
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        f(root,0,0,mp);
        vector<int>ans;
        for(auto [x,y]:mp){
            ans.push_back(y);
        }
        return ans;
    }
};