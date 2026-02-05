class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
         for(int i=0;i<n;i++){
            if(nums[i]>0){
                int x=(abs(nums[i]))%n;
                int idx=(i+x+n)%n;
                result[i]=nums[idx];
            }
            else if(nums[i]==0){
                result[i]=nums[i];
            }
            else{
                int x=(abs(nums[i]))%n;
                int idx=(i-x+n)%n;
                result[i]=nums[idx];
            }
         }
         return result;
    }
};