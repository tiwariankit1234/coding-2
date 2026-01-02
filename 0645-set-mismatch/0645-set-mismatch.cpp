class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctidx=nums[i]-1;
            if(nums[i]!=nums[correctidx]){
                swap(nums[i],nums[correctidx]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if((i+1)!=nums[i]){
              return {nums[i],i+1};
            }
        }
        return ans;
    }
};