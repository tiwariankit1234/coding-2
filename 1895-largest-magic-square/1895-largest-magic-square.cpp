class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxside = 1;
        vector<vector<int>> rowsum(m + 2, vector<int>(n + 2, 0)),
            colsum(m + 2, vector<int>(n + 2, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowsum[i + 1][j + 1] = rowsum[i + 1][j] + grid[i][j];
            }
        }
        for(auto it:rowsum){
            for(auto k:it){
                cout<<k<<" ";
            }
            cout<<endl;
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colsum[i + 1][j + 1] = colsum[i][j + 1] + grid[i][j];
            }
        }
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i + k - 1 < m and j + k - 1 < n) {
                        int rowysum = 0, colysum = 0;
                        bool ok=true;
                        for (int l = i; l <= (i + k - 1); l++) {
                            int x= rowsum[l + 1][j + k] - rowsum[l + 1][j];
                            if(x!=rowysum and rowysum!=0){
                                ok=false;
                                break;
                            }
                            rowysum=x;
                        }
                        bool flag=true;
                        for (int l = j; l <= (j + k - 1); l++) {
                            int x = colsum[i + k][l + 1] - colsum[i][l + 1];
                            if(x!=colysum and colysum!=0){
                                 flag=false;
                                break;
                            }
                            colysum=x;
                        }
                        int p = i, q = j, diagonalsum1 = 0, diagonalsum2 = 0;
                        while (p <= i + k - 1 and q <= j + k - 1) {
                            diagonalsum1 += grid[p][q];
                            p++;
                            q++;
                        }
                        p = i, q = j + k - 1;
                        while (p <= i + k - 1 and q >= 0) {
                            diagonalsum2 += grid[p][q];
                            p++;
                            q--;
                        }
                        if (rowysum == colysum and colysum == diagonalsum1 and
                            diagonalsum2 == diagonalsum1 and ok and flag)
                            return k;

                            // cout<<rowysum<<" "<<colysum<<" "<<diagonalsum1<<" "<<diagonalsum2<<" "<<i<<" "<<j<<" "<<k<<endl;
                    }
                    // colsum
                }
            }
        }
        return 1;
    }
};