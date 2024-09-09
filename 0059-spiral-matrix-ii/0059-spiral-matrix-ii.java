class Solution {
    public int[][] generateMatrix(int n) {
        int mat[][] = new int[n][n];

        int startRow = 0;
        int endRow = n-1;
        int startCol = 0;
        int endCol = n-1;
        int val = 1;

        while (startRow <= endRow && startCol <= endCol){

            //top
            for (int i = startCol; i <= endCol; i++) {
                mat[startRow][i] = val;
                val++;
            }

            //left
            for (int i = startRow+1; i <= endRow; i++) {
                mat[i][endCol] = val;
                val++;
            }

            //bottom
            for (int i = endCol-1; i >= startCol ; i--) {
              
                mat[endRow][i] = val;
                val++;
            }

            for (int i = endRow-1; i >= startRow+1; i--) {
               
                mat[i][startCol] = val;
                val++;
            }

            startRow++;
            startCol++;
            endRow--;
            endCol--;

        }

        return mat;
    }
}