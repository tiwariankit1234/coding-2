class Solution {
public:
    vector<int> advantageCount(vector<int>& arr, vector<int>& nums2) {
        vector<int>nums1=arr;
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        vector<int>ans(nums1.size());
        for(int i=0;i<n;i++){
            auto it=upper_bound(nums1.begin(),nums1.end(),nums2[i])-nums1.begin();
            if(it==nums1.size()){
            ans[i]=nums1[0];
             nums1.erase(nums1.begin());
            }
            else{
                ans[i]=nums1[it];
                nums1.erase(nums1.begin()+it);

            }   
        }
        return ans;
    }
};