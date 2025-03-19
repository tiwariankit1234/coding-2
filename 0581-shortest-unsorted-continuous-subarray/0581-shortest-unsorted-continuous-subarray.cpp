class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        int l=0,r=n-1;
        while(l<n){
            if(nums[l]==arr[l])
            l++;
            else
            break;
        }
           cout<<l<<endl;
        while(r>=0){
            if(nums[r]==arr[r])
          r--;
            else
            break;
        }
        if(l>=r)return 0;
        return r-l+1;
    }
};