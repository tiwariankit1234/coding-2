class Solution {
public:
    vector<TreeNode*> f(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = start; i <= end; ++i) {
            // Generate all possible left and right subtrees
            vector<TreeNode*> leftSubtrees = f(start, i - 1);
            vector<TreeNode*> rightSubtrees = f(i + 1, end);

            // Combine each left and right subtree with the root i
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return f(1, n);
    }
};
