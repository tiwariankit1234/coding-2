class Solution {
public:
    int findMinDifference(vector<string>& ans) {
        // first extract minutes and push in array sort it
        // last compare 24*60

        int n=ans.size();
        vector<int>minutes(n);

        for(int i=0;i<n;i++){
            string s=ans[i];
            int hours=stoi(s.substr(0,2));
            int min=stoi(s.substr(3));
            minutes[i]=hours*60+min;
        }

        sort(minutes.begin(),minutes.end());

          int difference=50000;
          for(int i=0;i<=n-2;i++){
            int newdifference=minutes[i+1]-minutes[i];
            difference=min(difference,newdifference);
          }

       return min(difference,24*60-minutes[n-1]+minutes[0]);
    }
};