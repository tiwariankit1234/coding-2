class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),maxprofit=0,minprice=INT_MAX;
        for(int i=0;i<n;i++){
            minprice=min(prices[i],minprice);
            maxprofit=max(maxprofit,prices[i]-minprice);
        }
        return maxprofit;
    }
};