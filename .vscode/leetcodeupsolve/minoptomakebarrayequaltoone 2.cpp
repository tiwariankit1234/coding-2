class Solution {
public:
//https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        
          // greedy algorithm
          int count=0;
         

        
        for(int i=0;i<nums.size();i++){
            int k=count;
            if(k%2){
                nums[i]=!nums[i];
            }
           if(nums[i]==0){
            
            count++;
           }
        }
        return count;
    }
};