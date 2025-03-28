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
int count=0;
vector<int> f(TreeNode* root,int distance){
    if(!root->left and !root->right)return {1};
    vector<int>lefty;
    if(root->left)lefty=f(root->left,distance);
    vector<int>righty;
    if(root->right)righty=f(root->right,distance);
    
    for(int i=0;i<lefty.size();i++){
        for(int j=0;j<righty.size();j++){
            if(lefty[i]+righty[j]<=distance)
            count++;
        }
    }
    vector<int>current;
    for(auto it:lefty)current.push_back(++it);
    for(auto it:righty)current.push_back(++it);

    return current;
    
}

    int countPairs(TreeNode* root, int distance) {
       f(root,distance);
       return count;
    }
};