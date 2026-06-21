class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int idx=0;
        int n=costs.size(),count=0;
        for(int i=0;i<n;i++){
            if(coins-costs[i]>=0){
                coins=coins-costs[i];
                 count++;
            }
        }
        return count;
    }
};