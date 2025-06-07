#define ll long long 
class Solution {
public:
    int n;
    ll dp[1001][3][501]; // day, state, transactions

    ll dfs(int i, int state, int k, vector<int>& prices) {
        if(k<0)return INT_MIN;
        if ( k == 0) return 0;
        if(i==n){
            if(state==1||state==2)
                return INT_MIN;
            return 0;
        }
        if (dp[i][state][k] != -1) return dp[i][state][k];

        ll ans = 0;

        if (state == 0) {

            ans = max({
                dfs(i + 1, 0, k, prices),                      // skip
                -prices[i] + dfs(i + 1, 1, k, prices),         // normal buy
                prices[i] + dfs(i + 1, 2, k, prices)           // short sell
            });
        } else if (state == 1 ) {
          
            ans = max({
                dfs(i + 1, 1, k, prices),                      // skip
                prices[i] + dfs(i + 1, 0, k - 1, prices)       // sell
            });
        } else {
            // In a short sell: buy back or skip
            ans = max({
                dfs(i + 1, 2, k, prices),                      // skip
                -prices[i] + dfs(i + 1, 0, k - 1, prices)      // buy back
            });
        }

        return dp[i][state][k] = ans;
    }

    ll maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, k, prices);
    }
};
