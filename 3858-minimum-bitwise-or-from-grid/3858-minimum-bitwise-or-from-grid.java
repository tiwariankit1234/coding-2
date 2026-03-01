class Solution {
    int min;
    HashSet<String> dp;
    public void solve(int[][] grid, int row, int currOR){
        if(row>=grid.length){ // all rows completed
            min = Math.min(min, currOR);
            return;
        }

        if(currOR>=min) return; // early stop
        String key = row + "," + currOR;
        if(dp.contains(key)) return; // already seen
        dp.add(key); // mar it as seen

        for(int j=0; j<grid[row].length; j++){
            // options for curr row
            solve(grid, row+1, (currOR | grid[row][j]));
        }
        
    }
    public int minimumOR(int[][] grid) {
        min = Integer.MAX_VALUE;
        dp = new HashSet<>();
        solve(grid, 0, 0);
        return min;
    }
}