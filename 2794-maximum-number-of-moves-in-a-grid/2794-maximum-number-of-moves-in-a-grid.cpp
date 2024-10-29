class Solution {
public:
 
int dp[1001][1001];
int f(int currentrow,int currentcol,vector<vector<int>>&grid){

    int m=grid.size()-1;
    int n=grid[0].size()-1;
     
     if(dp[currentrow][currentcol]!=-1)return dp[currentcol][currentcol];
    int steps1=0;
 
  
    if(currentrow-1>=0 and currentcol+1<=n and grid[currentrow-1][currentcol+1]>grid[currentrow][currentcol]){
      
        steps1+=1+f(currentrow-1,currentcol+1,grid);
    }

    // cout<<steps1<<" "<<currentrow<<" "<<currentcol<<" "<<endl;
        
      
   int steps2=0;
    
       if( currentcol+1<=n and grid[currentrow][currentcol+1]>grid[currentrow][currentcol]){
       
        steps2+=1+f(currentrow,currentcol+1,grid);
    }
      
    //    cout<<steps2<<" "<<currentrow<<" "<<currentcol<<" "<<endl;
     
     int steps3=0;
    if(currentrow+1<=m and currentcol+1<=n and grid[currentrow+1][currentcol+1]>(grid[currentrow][currentcol])){
      
        steps3+=1+f(currentrow+1,currentcol+1,grid);
    }

    //  cout<<steps3<<" "<<currentrow<<" "<<currentcol<<" "<<endl;
    
    return dp[currentrow][currentcol]=max(steps1,max(steps2,steps3));
}
    int maxMoves(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
           
           int maxsteps=0;
        for(int i=0;i<rows;i++){
           maxsteps=max(maxsteps,f(i,0,grid));
        }

        return maxsteps;
    }
};