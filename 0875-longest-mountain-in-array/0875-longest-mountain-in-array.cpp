class Solution {
public:

int longestBitonicSequence(vector<int>& arr, int n) {
    // Initialize two arrays to store the increasing and decreasing subsequences
    vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]

    // Calculate the longest increasing subsequence
    for (int i = 1; i < n; i++) {
     
            if (arr[i-1] < arr[i]) {
                dp1[i] = max(dp1[i-1]+1, dp1[i]);
            }
    
    }

    // Reverse the direction of nested loops to calculate the longest decreasing subsequence
    for (int i = n - 2; i >= 0; i--) {

            if (arr[i+1] < arr[i]) {
                dp2[i] = max(dp2[i], 1 + dp2[i+1]);
            }
        }
    

    int maxi = -1;

    // Find the maximum length of the bitonic subsequence
    for (int i = 0; i < n; i++) {
        if(dp1[i]>=2 and dp2[i]>=2)
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}



    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<=2)return 0;
        int maxi=longestBitonicSequence(arr,n);
        if( maxi==-1)return 0;
        
        return maxi;
    }
};