class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

            

           if(grid[0][0]==0)  pq.push({0, {0, 0}});
           else{
            pq.push({1,{0,0}});
           }
               
               int n = grid.size();
        int m = grid[0].size();

         vector<vector<int>>visited(n,vector<int>(m,0));
         visited[0][0]=1;

              int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
                cout<<diff<<" "<<row<<" "<<col<<" "<<endl;
             if(row==n-1 and col==m-1)
              return (health>diff);
             for (int i = 0; i < 4; i++)
            {
                // row - 1, col
                // row, col + 1
                // row - 1, col
                // row, col - 1
                int newr = row + dr[i];
                int newc = col + dc[i];

                 if (newr >= 0 && newc >= 0 && newr < n && newc < m and visited[newr][newc]==0){
                     visited[newr][newc]=1;
              if(grid[newr][newc]==1){
                pq.push({diff+1,{newr,newc}});
              }
              else{
                pq.push({diff,{newr,newc}});
              }
              visited[newr][newc]=1;
                 }

    }
        }   

        return false;
    } 
};