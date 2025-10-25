class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int l=0,h=n-1;
        int ans=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            //left sorted part
            if(arr[l]<=arr[mid]){
                ans=min(ans,arr[l]);
                l=mid+1;
            }
            else if(arr[mid]<=arr[h]){
                 ans=min(ans,arr[mid]);
                 h=mid-1;
            }
        }
        return ans;
    }
};