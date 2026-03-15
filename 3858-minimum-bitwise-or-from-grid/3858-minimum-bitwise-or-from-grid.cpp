class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = (1 << 17) - 1;
        for (int l = 16;l >= 0; l--) {
          ans = ans & ~(1 << l);

            for (int i = 0; i < m; i++) {
                int count = 0;
                bool ok=false;
                
                for (int j = 0; j < n; j++) {
                    int x = ans | grid[i][j];
                    if (x == ans) {
                        ok=true;
                        break;
                    }
                }
                if(!ok){
                    ans=ans|(1<<l);
                    break;
                }
            }
        }
        return ans;
    }
};