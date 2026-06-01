class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size(),totalcost=0;
        int i=n-1;
        while(i>=0){
            int count=0;
            while(i>=0 and count<=1){
                totalcost+=cost[i];
                i--;
                count++;
            }
            i--;
        }
        return totalcost;
    }
};