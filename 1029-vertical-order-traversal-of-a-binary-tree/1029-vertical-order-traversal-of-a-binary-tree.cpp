#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void inorder(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if (!root) return;
        
        // Visit left
        inorder(root->left, x - 1, y + 1, nodes);
        
        // Process current node
        nodes[x][y].insert(root->val);
        
        // Visit right
        inorder(root->right, x + 1, y + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;  // x -> y -> multiset of node values
        
        // Perform in-order traversal to populate the map
        inorder(root, 0, 0, nodes);

        vector<vector<int>> ans;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                for (auto val : q.second) {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
};
