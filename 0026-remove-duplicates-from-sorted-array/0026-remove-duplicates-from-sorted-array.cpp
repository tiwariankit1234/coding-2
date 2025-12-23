class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0,count=0,n=nums.size(),i=0;
         while(i<(n-1)){
            if(nums[i]==nums[i+1]){
                count++;
                nums[k++]=nums[i];
                while(i<(n-1) and nums[i]==nums[i+1]){
                    i++;
                }
                i++;
            }
            else if(nums[i]!=nums[i+1]){
                count++;
                nums[k++]=nums[i];
                i++;
            }
         }
         if(i!=n){
            nums[k++]=nums[i];
            count++;
         }
         return count;
    }
};