//https://leetcode.com/problems/n-ary-tree-level-order-traversal/?envType=problem-list-v2&envId=2tb72ufm

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// emplace back ka use
// ans vector me new level insert karne ke liye emplace_back() ka use karte hain
// ans[level].push_back insert karne ke liye
// class Solution { // 16 ms, faster than 98.53%
// public:
//     vector<vector<int>> ans;
//     vector<vector<int>> levelOrder(Node* root) {
//         dfs(root, 0);
//         return ans;
//     }
//     void dfs(Node* root, int level) {
//         if (root == nullptr) return;
//         if (level == ans.size()){ ans.emplace_back();
//         cout<<level<<" "<<ans.size()<<endl;
//         } // Need more level -> Add new level
//         ans[level].push_back(root->val);
//         for (Node* child : root->children)
//             dfs(child, level + 1);
//     }
// };



//bfs solution


class Solution { 
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
              ans.emplace_back();
             for (int i = q.size(); i >= 1; i--) {
                Node* curr = q.front(); q.pop();
               ans.back().push_back(curr->val);
                for (Node* child : curr->children) {
                    q.push(child);
                }
            }
          
        }
        return ans;
    }
};
