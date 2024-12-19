class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int currentsum=0,n=arr.size(),count=0;
        for(int i=0;i<n;i++){
            currentsum+=arr[i];
            if(currentsum==(i*(i+1))/2)count++;
        }
        return count;
    }
};