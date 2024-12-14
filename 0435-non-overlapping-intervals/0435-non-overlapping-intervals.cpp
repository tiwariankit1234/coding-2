class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
         }
         );


         int n=intervals.size();
        int minend=intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
        if(intervals[i][0]<minend){
            minend=min(intervals[i][1],minend);
            count++;
        }
        else{
          minend=intervals[i][1];
        }
        } 
        return count;
    }
};