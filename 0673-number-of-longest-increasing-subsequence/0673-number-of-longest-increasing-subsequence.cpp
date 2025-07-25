class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size(), ans = 1,cnt=0;
        vector<int> dp(n, 1),count(n,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        cout<<ans<<endl;
     for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] and dp[j]+1==dp[i]){
                count[i]+=count[j];
            }
        }
        if(dp[i]==1 and count[i]==0)count[i]=1;
        if(dp[i]==ans){
            cnt+=count[i];
        }
     }
        return cnt;
    }
};