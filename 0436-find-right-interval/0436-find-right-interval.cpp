class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& interval) {
        int n=interval.size();
        map<int,int>mp;
         // storing starting and indices
        for(int i=0;i<n;i++){
            int start=interval[i][0];
            mp.insert({start,i});
        }

        vector<int>ans;
        // find an element just greater than end in mp

        for(int i=0;i<n;i++){
            int end=interval[i][1];
           auto it=mp.lower_bound(end);
            if(it!=mp.end())
            ans.push_back(it->second);
            else
           {
            ans.push_back(-1);
           }
        
        }

         return ans;
    }
};