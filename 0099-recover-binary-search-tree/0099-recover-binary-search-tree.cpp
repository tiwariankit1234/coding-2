
class Solution {
public:
int idx=0;
void inorder(TreeNode* root,vector<int>&ans)
{
    if(root==NULL)return ;
       inorder(root->left,ans);
      ans.push_back(root->val);
   inorder(root->right,ans);
}

void inorder2(TreeNode* root,vector<int>&ans){
    if(root==NULL)return;

    inorder2(root->left,ans);
    
        root->val=ans[idx++];
        cout<<root->val<<endl;
     
     inorder2(root->right,ans);
}
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);

        sort(ans.begin(),ans.end());

        inorder2(root,ans);
    }
};