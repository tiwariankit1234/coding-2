class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        // Push all the left nodes to the stack
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        // Pop the top node from the stack
        TreeNode* node = st.top();
        st.pop();
        int val = node->val;
        
        // If the node has a right child, push all its left descendants
        if (node->right) {
            node = node->right;
            while (node) {
                st.push(node);
                node = node->left;
            }
        }
        
        return val;
    }
    
    bool hasNext() {
        // If there are elements in the stack, we have a next element
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */  
