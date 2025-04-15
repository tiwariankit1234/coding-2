
class Solution {
public:

vector<TreeNode*> f(int start,int end){
   vector<TreeNode*>ans;
    if(start>end ||end<start)return {NULL};
    if(start==end)return {new TreeNode(start)};
  
    for(int j=start;j<=end;j++){
          
       vector<TreeNode*>leftSubtree=f(start,j-1);
        vector<TreeNode*>rightSubtree=f(j+1,end);
        // if(root->val==3){
        //     for(auto it:leftSubtree){
        //         if(it)
        //         cout<<it->val<<" ";
        //     }
        //     cout<<endl;
        //     for(auto it:rightSubtree){
        //         if(it)
        //     cout<<it->val<<" ";
        //     }
        //     cout<<endl;
        // }
         for(auto left:leftSubtree){
            for(auto  right:rightSubtree){
                 TreeNode* root=new TreeNode(j);
                root->left=left;
                root->right=right;
                ans.push_back(root);
            }
         }
    }
    return ans;
 
}
    vector<TreeNode*> generateTrees(int n) {

     
     return f(1,n);
    }
};