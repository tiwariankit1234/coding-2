
class Solution {
public:
void f(TreeNode* root,int x,int y, map<int,multiset<pair<int,int>>>&mp){
    if(!root)return ;
  mp[x].insert({y,root->val});
  f(root->left,x-1,y+1,mp);
  f(root->right,x+1,y+1,mp);
  return ;
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>>mp;
        f(root,0,0,mp);
         vector<vector<int>>ans;
         for(auto &[x,st]:mp){
            vector<int>res;
            ans.push_back(res);
            for(auto [y,val]:mp[x]){
                ans.back().push_back(val);
            }
         }
         return ans;
    }
};