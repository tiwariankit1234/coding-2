// 3 25 7 8 10 15 20 5

// swapped nodes are not adjacent

// 3 5 8 7 10 15 20 25
// swapped nodes are adjacent
class Solution {
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

private:

void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);
 
    if(prev==NULL || prev->val>=root->val){
        if(first==NULL){
        first=prev;
        middle=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    inorder(root->right);
}
public:
    void recoverTree(TreeNode* root) {
        first=NULL,prev=NULL,middle=NULL,last=NULL;
        inorder(root);
          if(first and last)swap(first->val,last->val);
        else if(first and middle)swap(first->val,middle->val);
       

        return ;
    
    }
};