class Solution {
public:

void f(TreeNode *root,TreeNode* &prev,TreeNode* &first,TreeNode* &second,bool &flag){
    if(root==NULL)return;
    f(root->left,prev,first,second,flag);
     if(flag==false and prev!=NULL and prev->val>root->val){
        first=prev;
        flag=true;
     }
     if(flag and prev!=NULL and prev->val>root->val){
        second=root;
     }
    prev=root;
    f(root->right,prev,first,second,flag);
}
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* prev=NULL;
        bool flag=false;
      f(root,prev,first,second,flag);
    //   cout<<first->val<<" "<<second->val<<endl;
      swap(first->val,second->val);
      return ;
    }
};