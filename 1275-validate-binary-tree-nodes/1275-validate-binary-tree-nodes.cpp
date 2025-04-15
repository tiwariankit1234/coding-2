class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        // Count indegrees and check for more than one parent
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (++indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                if (++indegree[rightChild[i]] > 1) return false;
            }
        }

        // Find the root (node with 0 indegree)
        int count=0;
        int root;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
               count++;
               root=i;
               if(count>=2)return false;
            }
        }
        if(count==0)return false;

    

        // BFS to check connectivity and detect cycles
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : {leftChild[node], rightChild[node]}) {
                if (child != -1) {
                    if (visited[child]) return false; // Cycle detected
                    visited[child] = true;
                    q.push(child);
                }
            }
        }

        // All nodes must be visited (fully connected)
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};
