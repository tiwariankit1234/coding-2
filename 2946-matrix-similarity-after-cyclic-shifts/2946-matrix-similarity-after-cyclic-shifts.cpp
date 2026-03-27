class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>temp(m,vector<int>(n,0));
        if(k%n==0)return true;
        k=k%n;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i%2==0){
                    int newj=(j-k+n)%n;
                    temp[i][newj]=mat[i][j];
                }
                else{
                    int newj=(j+k+n)%n;
                    temp[i][newj]=mat[i][j];
                }
            }
         }
         for(auto it:temp){
            for(auto l:it)cout<<l<<" ";
            cout<<endl;
         }
         return temp==mat;
    }
};