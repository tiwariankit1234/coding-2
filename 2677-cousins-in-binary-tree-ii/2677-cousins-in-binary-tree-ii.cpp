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

void dfs(TreeNode* root,vector<int>&levelsum,int idx){
    if(!root)return ;
      
      cout<<root->val<<endl;
      int siblingsum=0;
   if(root->left)
   siblingsum+=root->left->val;
   if(root->right)
   siblingsum+=root->right->val;

   if(root->left) {root->left->val=levelsum[idx]-siblingsum;
   }
   if(root->right){ root->right->val=levelsum[idx]-siblingsum;
   }

    dfs(root->left,levelsum,idx+1);
    dfs(root->right,levelsum,idx+1);
    return ;
}




    TreeNode* replaceValueInTree(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        vector<int>result;

        while(q.size()>0){
            int size=q.size();
            int levelsum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                int val=node->val;
                levelsum+=val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }

            }
               result.push_back(levelsum);
             
        } 
        root->val=0;

        dfs(root,result,1);

        return root;


        
    }
};