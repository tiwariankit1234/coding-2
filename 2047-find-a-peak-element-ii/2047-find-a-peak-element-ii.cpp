class Solution {
public:
int f(vector<vector<int>>&arr,int mid){
    int m=arr.size(),n=arr[0].size();
    int maxrow=0,maxelement=INT_MIN;
    for(int i=0;i<m;i++){
        if(arr[i][mid]>arr[maxrow][mid]){
            maxrow=i;
            maxelement=max(maxelement,arr[i][mid]);
        }
    }
    return maxrow;
}
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            int maxrow=f(arr,mid);
            int leftmid=mid>0?arr[maxrow][mid-1]:INT_MIN;
            int rightmid=mid<(n-1)?arr[maxrow][mid+1]:INT_MIN;
            if(arr[maxrow][mid]>=leftmid and arr[maxrow][mid]>=rightmid)return {maxrow,mid};
             else if(arr[maxrow][mid]<rightmid)l=mid+1;
             else
             h=mid-1;
        }
        return {-1,-1};
    }
};