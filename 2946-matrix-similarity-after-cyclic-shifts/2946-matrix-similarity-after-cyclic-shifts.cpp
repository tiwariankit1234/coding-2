class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        
        if(k%n==0)return true;
        k=k%n;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i%2==0){
                    int newj=(j-k+n)%n;
                    if(mat[i][j]!=mat[i][newj])return false;
                }
                else{
                    int newj=(j+k+n)%n;
                    if(mat[i][j]!=mat[i][newj])return false;
                }
            }
         }
      
         return true;
    }
};