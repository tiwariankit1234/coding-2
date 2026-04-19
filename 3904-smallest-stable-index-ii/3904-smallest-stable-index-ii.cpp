class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>maxi(n,INT_MAX),mini(n,INT_MIN);
       maxi[n-1]=min(nums[n-1],maxi[n-1]);
       mini[0]=max(nums[0],mini[0]);
       for(int i=n-2;i>=0;i--){
        maxi[i]=min(maxi[i+1],nums[i]);
       }
       for(int i=1;i<n;i++){
        mini[i]=max(mini[i-1],nums[i]);
       }
       int ans=-1;
       for(int i=0;i<n;i++){
        if(mini[i]-maxi[i]<=k)return i;
       }
       return -1;
       
    }
};