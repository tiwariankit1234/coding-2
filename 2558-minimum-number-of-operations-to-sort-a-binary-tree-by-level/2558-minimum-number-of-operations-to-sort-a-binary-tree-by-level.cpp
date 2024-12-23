
class Solution {
public:

int  selectionsort(vector<int>&ans){
            int count=0;
    // Loop through each element in the vector except the last one
    for(int i=0;i<=ans.size()-1;i++){

        int minidx=i; // Assume the current index has the minimum value
        
        // Find the minimum value in the unsorted portion of the array
        for(int j=i;j<ans.size();j++){
            if(ans[j]<ans[minidx]){  // Update minidx if a smaller element is found
                minidx=j;
            }
        }
        
        // Swap the found minimum element with the first unsorted element
        if(minidx!=i){
        swap(ans[minidx],ans[i]);
             count++;
        }
    }
    return count;
}



TreeNode* reverseOddLevels(TreeNode* root,int& count) {
        if (!root) return NULL;

        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0; // Start at level 0 (even)

        while (!q.empty()) {
            int size = q.size();
            std::vector<int> currentLevelNodes;

            // Process nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node->val);

                // Add children to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse nodes at odd levels
         {
                int n = currentLevelNodes.size();
              count+=selectionsort(currentLevelNodes);

            }

            level++; // Increment level
        }

        return root;
    }



    int minimumOperations(TreeNode* root) {
        int count=0;
         reverseOddLevels(root,count);
         return count;
    }
};