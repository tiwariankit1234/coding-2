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
vector<TreeNode*>temp;
void f1(TreeNode* root){
    if(!root)return ;
        f1(root->left);
        temp.push_back(root);
        f1(root->right);
        return ;
}
TreeNode* f2(int low,int high,TreeNode* root){
    if(high<low)return NULL;
    int mid=(low+high)/2;
    TreeNode* node=temp[mid];
    node->left=f2(low,mid-1,root);
    node->right=f2(mid+1,high,root);
    return node;
}


    TreeNode* balanceBST(TreeNode* root) {
        f1(root);
        int n=temp.size();
       return f2(0,n-1,root);
    }
};