class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* prev) {
        if (node == NULL) return true;


        if (!validate(node->left,prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
    //    if(node)cout<<node->val<<" ";
    //    if(prev)cout<<prev->val<<" ";
    //    cout<<endl;
        prev=node;
        bool t=validate(node->right, prev);
        // if(node->right)cout<<node->right->val<<" ";
        // if(prev)cout<<prev->val<<" ";
        // cout<<endl;
        return t;
    }
};