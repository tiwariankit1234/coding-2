class Solution {
public:
    // map root values with TreeNodes, to get a node with this value in O(1)
    unordered_map<int, TreeNode*> rMap;
  
    // counter for root and leaves, because root with count = 1 is main tree ROOT
    unordered_map<int, int> cMap;
  
    // counter var to track how many trees i have used from trees array
    int count = 0;
    
    // a simple dfs function if curr node is leaf, then it's counted in Map
    void countLeaves(TreeNode* root){
      if(!root) return;
      if(!root->left && !root->right) cMap[root->val]++;
      countLeaves(root->left); 
      countLeaves(root->right);
    }
  
    // using the main ROOT we found, try building the complete tree
    void buildTree(TreeNode* root){
      if(!root) return;
      
      // this node is leaf for current main tree
      // if this can be found in our rMap, means it can be extended more
      if(!root->left && !root->right) {
        if(rMap.count(root->val)){ 
          count++;
          root->left = rMap[root->val]->left;
          root->right = rMap[root->val]->right;
          // remove elements after using or may get stuck in endless loop
          rMap.erase(root->val);
        } 
      }
      
      // dfs calls to reach to leaf of this our current tree
      buildTree(root->left);
      buildTree(root->right);
    }
    
    // functions to check if final Tree is a Valid BST
    bool isValidBST(TreeNode* root) {
      TreeNode* prev = NULL;
      return valid(root, prev);
    }
    bool valid(TreeNode* root, TreeNode* &prev){
      if(!root) return true;
      if(!valid(root->left, prev)) return false;
      if(prev!=NULL && prev->val >= root->val) return false;
      prev = root;
      return valid(root->right, prev);
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
      rMap.clear();
      cMap.clear();
      
      // for each root, increase counter, and call dfs function to count leaves
      // map root value to root node
      for(auto &root: trees){ 
        if(root->left || root->right) countLeaves(root);
        cMap[root->val]++;
        rMap[root->val] = root;
      }
      
      TreeNode* ROOT = NULL;
      // in all roots, try finding root with counter = 1
      // it will be root of our main tree
      for(auto &t: trees){
        if(cMap[t->val] == 1) {
          count = 1;
          ROOT = rMap[t->val];
          rMap.erase(t->val);
          break; 
        }
      }
      
      // from main root traverse down to it's leaf, then append new roots to leafs
      // if found, and extend the tree and do again for new leaves now
      buildTree(ROOT);
      
      // at the end if we used all roots from trees array
      // and it's a valid BST then we can return it
      if(count != trees.size() || !isValidBST(ROOT)) return NULL;
      return ROOT;
    }
};