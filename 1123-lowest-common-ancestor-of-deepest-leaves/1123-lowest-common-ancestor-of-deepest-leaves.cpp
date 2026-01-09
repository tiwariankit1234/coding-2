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
void traversal(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
     if(!root->left and !root->right)return ;
     if(root->left){
        mp[root->left]=root;
        traversal(root->left,mp);
     }
     if(root->right){
        mp[root->right]=root;
        traversal(root->right,mp);
     }
     return ;
}
void bfs(TreeNode* root,vector<vector<TreeNode*>>&ans){
    queue<TreeNode*>q;
    q.push(root);
    while(q.size()){
        int n=q.size();
        vector<TreeNode*>level;
        for(int i=0;i<n;i++){
           auto it=q.front();
           level.push_back(it);
           q.pop();
           if(it->left)q.push(it->left);
           if(it->right)q.push(it->right);
        }
        ans.push_back(level);
    }
    return ;
}
TreeNode* f(TreeNode* p,TreeNode* q,unordered_map<TreeNode*,TreeNode*>&mp){
    if(p==q)return p;
    return f(mp[p],mp[q],mp);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       unordered_map<TreeNode*,TreeNode*>mp;

        mp[root]=new TreeNode(-1);
        traversal(root,mp);
        vector<vector<TreeNode*>>ans;
        bfs(root,ans);
        int n=ans.size();
        if(ans[n-1].size()==1)return ans[n-1][0];
        else{
         int k=ans[n-1].size();
        return f(ans[n-1][0],ans[n-1][k-1],mp);
        }
        return NULL;
    }
};