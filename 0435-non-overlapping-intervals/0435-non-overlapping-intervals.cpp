class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>&arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int count=0,l=0,r=1;
        while(r<n){
            int currstart=arr[r][0],currend=arr[r][1];
            int prevstart=arr[l][0],prevend=arr[l][1];
            if(currstart>=prevend){
               l=r;r++;
            }
            else if(currstart<prevend){
                 if(prevend<currend){
                    r++;
                    count++;
                 }
                 else{
                    l=r;
                    r++;
                    count++;
                 }
            }
        }
        return count;
    }
};