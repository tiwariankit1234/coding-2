class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int>candies(n,1);
        // for left part
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1] and candies[i]<=candies[i+1]){
                candies[i]=candies[i+1]+1;
            }
        }
        // for(auto it:candies)
        // cout<<it<<" ";
        
        return accumulate(candies.begin(),candies.end(),0);
    }
};