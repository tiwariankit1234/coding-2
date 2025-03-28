
class Solution {
public:
void buildAdjacency(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj,unordered_set<TreeNode*>&leafnode) {
    if (!root) return;
    if(!root->left and !root->right){
       leafnode.insert(root);
        
    }
  
    
    if (root->left) {
        adj[root].push_back(root->left);
        adj[root->left].push_back(root); // Undirected connection
        buildAdjacency(root->left, adj,leafnode);
    }

    if (root->right) {
        adj[root].push_back(root->right);
        adj[root->right].push_back(root); // Undirected connection
        buildAdjacency(root->right, adj,leafnode);
    }
}
int bfs(TreeNode* node,unordered_map<TreeNode*, vector<TreeNode*>>& adj,int dist,unordered_set<TreeNode*>&leaf){
       unordered_set<TreeNode*>st;
 
    queue<TreeNode*>q;
    q.push(node);
    int level=0,ans=0;
    
    while(q.size()>0){
    int n=q.size();
    for(int i=0;i<n;i++){
        TreeNode* temp=q.front();
        q.pop();
        st.insert(temp);
        if(level<=dist){
            if(leaf.find(temp)!=leaf.end() and temp!=node){
                ans++;
            }
        }
        if(level>dist)return ans;
        for(auto it:adj[temp]){
            if(st.find(it)==st.end()){
                q.push(it);
            }
        }
       
    }
    level++;
}
 return ans;
}

    int countPairs(TreeNode* root, int dist) {
         unordered_set<TreeNode*>leafnode;
        unordered_map<TreeNode*, vector<TreeNode*>>adj;
        buildAdjacency(root,adj,leafnode);
       

        unordered_set<TreeNode*>s;
        int ans=0;
        for(auto it:leafnode){
            if(s.find(it)==s.end()){
                s.insert(it);
               ans+=bfs(it,adj,dist,leafnode);
            }
        }

     return ans/2;

    }
};