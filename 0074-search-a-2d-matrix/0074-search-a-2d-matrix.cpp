class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m=arr.size(),n=arr[0].size();
        int l=0,h=m-1,ans=-1;
        while(l<=h){
          int mid=(l+h)/2;
          if(arr[mid][n-1]>target){
            ans=mid;
            h=mid-1;
          }
          else if(arr[mid][n-1]<target){
          
            l=mid+1;
          }
          else if(arr[mid][n-1]==target){
            return true;
          }
        }
        if(ans==-1)return false;
        l=0,h=n-1;
        while(l<=h){
           int mid=(l+h)/2;
           if(arr[ans][mid]<target){
            l=mid+1;
           }
           else if(arr[ans][mid]>target){
            h=mid-1;
           }
           else if(arr[ans][mid]==target){
            return true;
           }
        }
        return false;
    }
};