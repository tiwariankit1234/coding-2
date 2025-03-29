
class Solution {
public:
TreeNode* bfs(TreeNode* root,int val,int depth){

queue<TreeNode*>q;
q.push(root);
int level=2;
while(q.size()>0){
    int n=q.size();
    for(int i=0;i<n;i++){
        TreeNode* temp=q.front();
        q.pop();
        if(level==depth){
            TreeNode* prevleft= temp->left;
            TreeNode* prevright=temp->right;
            TreeNode* newleft=new TreeNode(val);
            TreeNode* newright=new TreeNode(val);
            temp->left=newleft;
            temp->right=newright;
            newleft->left=prevleft;
            newright->right=prevright;
          
        }
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
    if(level==depth)return root;
    level++;
    
}

return root;


}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
       return bfs(root,val,depth);
    }
};