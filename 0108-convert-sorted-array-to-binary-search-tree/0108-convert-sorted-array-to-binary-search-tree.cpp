
class Solution {
public:

TreeNode* f(int low,int high,vector<int>& nums){
    if(low>high)return NULL;

    int mid=(low+high)/2;

    TreeNode* root=new TreeNode(nums[mid]);
    root->left=f(low,mid-1,nums);
    root->right=f(mid+1,high,nums);

    return root;

}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();

           return f(0,n-1,nums);

    }
};