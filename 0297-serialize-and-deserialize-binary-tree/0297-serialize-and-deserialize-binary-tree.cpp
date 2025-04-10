/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
string s="";
void f(TreeNode* root){
 if(!root){
    s+="NULL,";
    return;
 }
  s+=to_string(root->val)+",";
  f(root->left);
  f(root->right);
  return ;
}
TreeNode* buildTree(queue<string>&q){
    string t=q.front();
     q.pop();
     if(t=="NULL")return NULL;
     TreeNode* root=new TreeNode(stoi(t));
     root->left=buildTree(q);
     root->right=buildTree(q);
     return root;
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        f(root);
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        int n=data.size();
        string s="";
        for(int i=0;i<n;i++){
            if(data[i]==','){
                q.push(s);
                s="";
            }
            else{
               s+=data[i];
             
            }
        }
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));