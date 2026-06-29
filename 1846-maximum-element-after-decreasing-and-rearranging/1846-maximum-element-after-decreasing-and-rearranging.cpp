class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int maxelement=1;
        arr[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]==1)continue;
            else {
                arr[i]=min(arr[i],arr[i-1]+1);
                maxelement=max(maxelement,arr[i]);
            }
        }
        return maxelement;
    }
};