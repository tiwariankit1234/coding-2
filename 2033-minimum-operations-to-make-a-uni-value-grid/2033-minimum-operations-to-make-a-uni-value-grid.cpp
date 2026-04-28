class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans=0;
        vector<int>temp;
        for(auto it:grid){
            for(auto k:it)temp.push_back(k);
        }
        sort(temp.begin(),temp.end());
        if(temp.size()==1)return 0;
        unordered_set<int>st;
        for(auto it:temp){
            st.insert(it%x);
        }
        if(st.size()>=2)return -1;
        int n=temp.size();
        int req=0;
        
        
            req=temp[n/2];
        
      
        for(auto it:temp){
            ans+=(abs(req-it))/x;
        }
        return ans;
    }
};