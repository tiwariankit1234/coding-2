class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
         vector<vector<int>>mat(n,vector<int>(n,0));
        for(auto it:queries){
            int rows1=it[0],rows2=it[2];
            int cols1=it[1],cols2=it[3];
            
            mat[rows1][cols1]+=1;
             if((rows2+1)<n and (cols2+1)<n){
              mat[rows2+1][cols2+1]+=1;
             }
            //  cout<<rows2<<"' "<<cols1<<endl;
            if((rows2+1)<n){
                mat[rows2+1][cols1]+=-1;
            }
            if(cols2+1<n){
                mat[rows1][cols2+1]+=-1;
            }
            //   mat[rows2][cols1]-=1;
            //    if((cols2+1)<n){
            //   mat[rows2][cols2+1]+=-1;
             }
            
        for(int i=0;i<n;i++){
           for(int j=1;j<n;j++){
            mat[i][j]+=mat[i][j-1];
           }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]+=mat[i-1][j];
            }
        }
        return mat;
    }
};