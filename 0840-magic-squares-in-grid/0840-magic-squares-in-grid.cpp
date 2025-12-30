class Solution {
public:

bool checkmagicSquare(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    int rowstart = i, colstart = j;
    int diagonalsum1 = 0, diagonalsum2 = 0;

    int count=0;
for(int i=rowstart;i<=rowstart+2;i++){
    for(int j=colstart;j<=colstart+2;j++){
        if(grid[i][j]==5)
        count++;
    }
    if(count>=2)return false;
}

    // Check if the 3x3 square contains only numbers from 1 to 9
    for (int r = rowstart; r < rowstart + 3; ++r) {
        for (int c = colstart; c < colstart + 3; ++c) {
            if (grid[r][c] < 1 || grid[r][c] > 9) return false;
        }
    }

    // Calculate diagonal sums
    diagonalsum1 = grid[rowstart][colstart] + grid[rowstart + 1][colstart + 1] + grid[rowstart + 2][colstart + 2];
    diagonalsum2 = grid[rowstart][colstart + 2] + grid[rowstart + 1][colstart + 1] + grid[rowstart + 2][colstart];

    cout<<"diagonalsum1"<<diagonalsum1<<" "<<"diagonalsum2"<<diagonalsum2<<" "<<endl;

    if (diagonalsum1 != 15 || diagonalsum2 != 15) return false;

    // Check sums of all rows and columns
    for (int r = rowstart; r < rowstart + 3; ++r) {
        int rowSum = 0;
        for (int c = colstart; c < colstart + 3; ++c) {
            rowSum += grid[r][c];
        }
        if (rowSum != 15) return false;
    }

    for (int c = colstart; c < colstart + 3; ++c) {
        int colSum = 0;
        for (int r = rowstart; r < rowstart + 3; ++r) {
            colSum += grid[r][c];
        }
        if (colSum != 15) return false;
    }

    return true;
}

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if((checkmagicSquare(grid,i,j)))

                count++;
            }
        }
        return count;
    }
};