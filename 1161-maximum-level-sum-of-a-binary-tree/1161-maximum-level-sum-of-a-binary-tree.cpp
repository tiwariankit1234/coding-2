#define ll long long
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        ll maxsum=INT_MIN,sum=0,level=1,maxlevel=-1;
        while(q.size()){
            int n=q.size();
            sum=0;
            for(int i=0;i<n;i++){
             TreeNode* temp=q.front();
             q.pop();
             sum+=temp->val;
             if(temp->left)q.push(temp->left);
             if(temp->right)q.push(temp->right);
            }
             if(sum>maxsum){
                maxsum=sum;
                maxlevel=level;
             }
             level++;
            
        }
        return (int)maxlevel;
    }
};