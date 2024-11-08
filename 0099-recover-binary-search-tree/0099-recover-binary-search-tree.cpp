
class Solution {
public:

void inorder(TreeNode* root,vector<int>&ans)
{
    if(root==NULL)return ;
       inorder(root->left,ans);
      ans.push_back(root->val);
   inorder(root->right,ans);
}

void inorder2(TreeNode* root,vector<int>&ans,int& idx){
    if(root==NULL)return;

    inorder2(root->left,ans,idx);
    
        root->val=ans[idx];
        idx++;
        // cout<<root->val<<endl;
     
     inorder2(root->right,ans,idx);
}
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);

        sort(ans.begin(),ans.end());
         int idx=0;
        inorder2(root,ans,idx);
    }
};