class Solution {
public:
    int check( int steps, int m, int n, vector<vector<int>>& arr) {
        int uppercount=0;

        for(int i=0;i<=(m-steps);i++){
            for(int j=0;j<=(n-steps);j++){
            bool isSquare=true;


            for(int x=i;x<i+steps;x++){
                for(int y=j;y<j+steps;y++){
                    if(arr[x][y]!=1)
                    {
                        isSquare=false;
                        break;
                    }
                }
                if(isSquare==false)break;
            }
            if(isSquare)uppercount++;
            }
        }
        return uppercount;
    }

    int countSquares(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        int maxsteps = min(m, n);  // Maximum size for square submatrices
        int count = 0;
        
        // Check for all squares of size 1x1, 2x2, ..., up to maxSteps x maxSteps
       for(int steps=1;steps<=maxsteps;steps++){
        count+=check(steps,m,n,arr);
       }
        
        return count;
    }
};
