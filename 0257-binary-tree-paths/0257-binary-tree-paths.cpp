
class Solution {
public:
 void f(TreeNode* root,string s,vector<string>&ans){
if(!root)return ;
    if(!root->left and !root->right){
         
     if(!s.empty()){
        s+="->"+to_string(root->val);
     }
     else{
        s+=to_string(root->val);
     }
        ans.push_back(s);
        return ;
    }
    if(!root)return ;
    
    
     if(!s.empty()){
        s+="->"+to_string(root->val);
     }
     else{
        s+=to_string(root->val);
     }
     
     f(root->left,s,ans);
    
     f(root->right,s,ans);
     return ;
 }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        f(root,"",ans);
        return ans;
    }
};