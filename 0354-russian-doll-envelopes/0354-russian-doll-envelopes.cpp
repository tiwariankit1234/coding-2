class Solution {
public:
vector<int>dp;
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
    int maxEnvelopes(vector<vector<int>>& arr) {
         int m=arr.size(),n=arr[0].size();
         sort(arr.begin(),arr.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]<b[0])
            return true;
            else if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return false;
         });

         vector<int>height;
         for(auto it:arr){
            height.push_back(it[1]);
         }
       


          return  lengthOfLIS(height);

    }
};