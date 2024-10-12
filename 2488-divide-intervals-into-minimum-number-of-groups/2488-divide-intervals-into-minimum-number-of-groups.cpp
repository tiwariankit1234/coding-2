class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
    
        int maxevent=0;
        map<int,int>mp;
         for(auto it:intervals){
            int start=it[0];
            int end=it[1]+1;
            mp[start]++;
            mp[end]--;
         }
           int sum=0;
           for(auto it:mp){
                sum+=it.second;
                // if(sum==4){
                //     for(auto it:mp){
                //         cout<<it.first<<" "<<it.second<<endl;
                //     }
                // }
                maxevent=max(sum,maxevent);
            }

          return maxevent;
    }
};