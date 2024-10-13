class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<pair<int,int>>v;
        // element index
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                v.push_back({nums[i][j],i});
            }
        }

        sort(v.begin(),v.end());
        n=v.size();
        cout<<n;

        int i=0,j=0;
        int range=INT_MAX;
        int rangestart=0;
        int rangeend=INT_MAX;

        //key represents index freq
        while(j<n){
          int element=v[j].first;
          int index=v[j].second;
          mp[index]++;
          while(mp.size()==nums.size()){
          if((element-v[i].first)<range){
        rangeend=element;
        rangestart=v[i].first;
        range=rangeend-rangestart;
          }
           mp[v[i].second]--;
           if(mp[v[i].second]==0)mp.erase(v[i].second);
           i++;
          }
          j++;

        }
        return {rangestart,rangeend};
    }
};