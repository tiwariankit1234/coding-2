
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftht = lefty(root);
        int rightht = righty(root);
        if (leftht == rightht) {
            return (1 << leftht)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int lefty(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }

    int righty(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->right;
            height++;
        }
        return height;
    }
};