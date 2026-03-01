class Solution {
public:
int gans=INT_MAX;
unordered_map<long long, int> dp;
    int  f(int i,int req, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(req>=gans)return INT_MAX;
        if (i == m) {
            gans=min(gans,req);
            return req;
        }
        int ans = INT_MAX;
         long long key = ((long long)i << 32) | req;
         if(dp.find(key)!=dp.end())return dp[key];
        for (int j = 0; j < n; j++) {
         ans=min(ans,f(i + 1, req|grid[i][j], grid));
        }
        return dp[key]=ans;
    }
    int minimumOR(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.clear();
        //  cout<<m<<" "<<n<<endl;
        f(0,0,grid);
        return gans;
    }
    
};