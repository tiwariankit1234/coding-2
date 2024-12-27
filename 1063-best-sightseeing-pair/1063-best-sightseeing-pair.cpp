class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxleftelement=values[0];
        int maxvalue=0;
        int ans=0;
        for(int i=1;i<n;i++){
          maxvalue=max(maxvalue,maxleftelement+values[i]-i);
          maxleftelement=max(maxleftelement,values[i]+i);
        }
        return maxvalue;
    }
};