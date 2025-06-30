class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxlength=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if(nums[j]-nums[i]>=2){
                break;
               }
               else if(nums[j]-nums[i]==1){
                maxlength=max(maxlength,j-i+1);
               }
            }
        }
        return maxlength;
    }
};