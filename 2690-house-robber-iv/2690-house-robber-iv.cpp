class Solution {
public:
bool check(int mid,vector<int>&nums,int k){
     int maxamount=mid;
      int n=nums.size();
      int count=0;
      for(int i=0;i<n;i++){
        if(nums[i]<=maxamount){
            // cout<<i<<" "<<nums[i]<<" "<<maxamount<<endl;
            count++;
            i++;
        }
      }
      return (count>=k);
}
    int minCapability(vector<int>& nums, int k) {
        int ans=0;
        int low=1,high=*max_element(nums.begin(),nums.end());
      
        // sort(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};