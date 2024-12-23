
class Solution {
public:

int  selectionsort(vector<int>ans){
            int count=0;
            int n=ans.size();
            vector<int>copy=ans;
            sort(copy.begin(),copy.end());
           map<int,int>mp;
            for(int i=0;i<(n);i++){
                mp[ans[i]]=i;
            }

            // for(auto it:mp){
            //     cout<<it.first<<" "<<it.second<<" ";
            // }
            // cout<<endl;

            // for(auto it:copy){
            // cout<<it<<" ";

            // }

           

            for(int i=0;i<n;i++){
                 if(copy[i]!=ans[i]){
                    int index=mp[copy[i]];
                    mp[ans[i]]=index;
                    swap(ans[i],ans[index]);
                    count++;
                 }
            }

            cout<<count<<endl;
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