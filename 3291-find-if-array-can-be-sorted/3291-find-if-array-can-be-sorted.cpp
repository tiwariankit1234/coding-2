class Solution {
public:
bool issorted(vector<int>&arr){
    int n=arr.size();
    int count=0;
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            count++;
        }
    }
    if(count==(n-1))return true;
    return false;
}
    bool canSortArray(vector<int>& arr) {
        int n=arr.size();
       
          for (int i = 0; i < n - 1; ++i) {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if elements are in the wrong order
            if (arr[j] > arr[j + 1] and __builtin_popcount(arr[j])==__builtin_popcount(arr[j+1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
   return issorted(arr);
    }
};