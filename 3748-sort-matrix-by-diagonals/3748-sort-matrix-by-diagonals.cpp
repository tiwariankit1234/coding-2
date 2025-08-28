class Solution {
public:
void fill(int start,int end,vector<int>&ans,vector<vector<int>>&grid){
      int m=grid.size();
        int n=grid[0].size();
            int l=0;
        while(start<m and end<n){
          grid[start++][end++]=ans[l++];
            
        }
}

void fill2(int start,int end,vector<int>&ans,vector<vector<int>>&grid){
      int m=grid.size();
        int n=grid[0].size();
            int l=0;
        while(start<m and end<n){
          grid[start++][end++]=ans[l++];
        }
}


    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=n-1;j>=1;j--){
            vector<int>ans;
            int i=0,k=j;
            for( i=0;i<m;i++){
                if(k==m)break;
                ans.push_back(grid[i][k]);
                k++;
            }
            sort(ans.begin(),ans.end());
            fill(0,j,ans,grid);
        }

        for(int k=0;k<m;k++){
            vector<int>ans;
             int x=k,y=0;
            while(x<m and y<n){
            ans.push_back(grid[x][y]);
            x++;
            y++;
        }
            
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
         fill2(k,0,ans,grid);
    }
         return grid;
    }
    
};