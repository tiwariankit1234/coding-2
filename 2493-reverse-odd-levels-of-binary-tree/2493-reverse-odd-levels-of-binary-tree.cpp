
class Solution {
public:

 
    TreeNode* reverseOddLevels(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);
       TreeNode* node;
       int level=0;
       while(q.size()>0){
         int size=q.size();
           
           vector<TreeNode*>currentLevelNode; 
         for(int i=0;i<size;i++){    // current level
             node=q.front();
               currentLevelNode.push_back(node);
             q.pop();
            if(node->left and node->right){
                q.push(node->left);
                q.push(node->right);
            }

        
         }
          if(level%2){
           int n=currentLevelNode.size();
            int i=0;
            while(i<(n/2)){
                swap(currentLevelNode[i]->val,currentLevelNode[n-i-1]->val);
                i++;
            }
          }
          level++;
       }
       return root;
    }
};