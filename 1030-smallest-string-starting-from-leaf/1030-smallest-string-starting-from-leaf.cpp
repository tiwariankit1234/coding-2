
class Solution {
public:
string small="";
void f(TreeNode* root,string currentstring){
    if(!root->left and !root->right){
       currentstring.push_back('a'+root->val);
        reverse(currentstring.begin(),currentstring.end());
        
        if(small==""||currentstring<small){
            small=currentstring;
            return;
        }
        return ;
    }
    currentstring.push_back('a'+root->val);
    if(root->left){
  
        f(root->left,currentstring);
    }
    if(root->right){
        
        f(root->right,currentstring); 
    }
    return  ;
}
    string smallestFromLeaf(TreeNode* root) {
        f(root,"");
     return small;
    }
};