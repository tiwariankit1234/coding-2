class Solution {
public:
 int m,n;

 int dx[5]={-1,0,1,0,-1};

 bool isValid(int i,int j, vector<vector<int>>&visited){
    if(i>=0 and i<m and j>=0 and j<n and visited[i][j]==0)return true;
    return false;
 }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m=isWater.size();
       n=isWater[0].size();

         vector<vector<int>> visited(m, vector<int>(n, 0));

           vector<vector<int>> height(m, vector<int>(n, 0));

            queue<pair<int,int>>q;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(isWater[i][j]==1){
                        height[i][j]=0;
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
               int row,col,level=1;
            while(q.size()>0){

                int size=q.size();
                for(int i=0;i<size;i++){
                auto [row,col]=q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int nrow=row+dx[k];
                    int ncol=col+dx[k+1];
                    if(isValid(nrow,ncol,visited)){
                        visited[nrow][ncol]=1;
                        q.push({nrow,ncol});
                        height[nrow][ncol]=level;
                    }
                }
            }
           level++; 
            } 
         return height;
    }
};