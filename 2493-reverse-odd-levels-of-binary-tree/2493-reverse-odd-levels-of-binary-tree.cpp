#include <queue>
#include <vector>



class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0; // Start at level 0 (even)

        while (!q.empty()) {
            int size = q.size();
            std::vector<TreeNode*> currentLevelNodes;

            // Process nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                // Add children to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse nodes at odd levels
            if (level % 2 == 1) {
                int n = currentLevelNodes.size();
                for (int i = 0; i < n / 2; i++) {
                    // Swap the nodes themselves
                    std::swap(currentLevelNodes[i]->val, currentLevelNodes[n - i - 1]->val);
                }
            }

            level++; // Increment level
        }

        return root;
    }
};
