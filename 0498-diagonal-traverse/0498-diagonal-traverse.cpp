class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int m=mat.size(),n=mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            mp[i+j].push_back(mat[i][j]);
            }
        }
        bool flag=true;
        for(auto it:mp){
            auto vec=it.second;
            if(flag==true)
            reverse(vec.begin(),vec.end());
            for(auto k:vec){
                ans.push_back(k);
            }
            flag=!flag;
        }
        return ans;
    }
};