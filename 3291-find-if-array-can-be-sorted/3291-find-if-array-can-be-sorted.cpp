class Solution {
public:
    bool canSortArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> bitCount(n);

        // Step 1: Precompute popcounts
        for (int i = 0; i < n; ++i) {
            bitCount[i] = __builtin_popcount(arr[i]);
        }

        // Step 2: Check if subarrays with same popcount are sorted
        int i = 0;
        int prevmax=INT_MIN,currentmin=INT_MAX,currentmax=INT_MIN;
        for(auto it:bitCount){
            cout<<it<<" ";
        }
        cout<<endl;
        while (i < n) {
            int j = i;
            currentmin=INT_MAX,currentmax=INT_MIN;
            while (j < n && bitCount[j] == bitCount[i]) {
                 currentmin=min(arr[j],currentmin);
                 currentmax=max(arr[j],currentmax);
                j++;
            }
            i = j;
            cout<<prevmax<<" "<<currentmin<<" "<<currentmax<<" "<<endl;
            if(prevmax>currentmin)return false;
            prevmax=currentmax;
        }

        return true;
    }
};
