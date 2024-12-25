#define ll long long
class Solution {
public:
TreeNode* reverseOddLevels(TreeNode* root,vector<int>&ans) {
       queue<TreeNode*>q;
       q.push(root);
       TreeNode* node;
       int level=0;
       while(q.size()>0){
         int size=q.size();
           
        int maxelement=INT_MIN;
         for(int i=0;i<size;i++){    // current level
             node=q.front();
            //  cout<<node->val<<" ";
              maxelement=max(node->val,maxelement);
             q.pop();
            if(node->left){
                q.push(node->left);
               
            }
             if(node->right){
                q.push(node->right);
               
            }
         }
        //  cout<<endl;
          ans.push_back(maxelement);
       
       }
       return root;
    }




    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>ans;
        reverseOddLevels(root,ans);
        return ans;
    }
};