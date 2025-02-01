class Solution {
public:
bool binary_search(int start,int end,vector<int>&indices){
    int l=0,h=indices.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(start<=indices[mid] and indices[mid]<=end)
            return true;
            else if(indices[mid]>end){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
     return false;
}
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
         vector<int>indices;
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                indices.push_back(i);
            }
        }
        vector<bool>ans(queries.size());
        int j=0;
       for(auto it:queries){
          ans[j++]=!binary_search(it[0]+1,it[1],indices);
       }
       return ans;
    }
};