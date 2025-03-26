
class Solution {
public:
// pair<int,int >p,q;
unordered_map<int,pair<int,int>>mp;
void f(TreeNode* root,int x,int y,int depth,int parent){
    if(!root)return ;
     mp[root->val]={depth,parent};
    f(root->left,x,y,depth+1,root->val);
    f(root->right,x,y,depth+1,root->val);
    return;
}
    bool isCousins(TreeNode* root, int x, int y) {
        f(root,x,y,0,-1);
        // if(p.first==q.first and p.second!=q.second)return true;
        // else
        // return false;
         if(mp[x].first==mp[y].first and mp[x].second!=mp[y].second)return true;
         else
         return false;
    }
};