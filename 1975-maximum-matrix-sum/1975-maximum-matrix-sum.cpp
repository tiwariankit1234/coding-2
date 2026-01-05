#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        ll sum=0,countnegative=0,minelement=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]<0){
                    countnegative++;
                }
                minelement=min((int)minelement,(abs(mat[i][j])));
                sum+=abs(mat[i][j]);
            }
        }
        if((countnegative%2)==0)return sum;
        else{
            return sum-minelement-minelement;
        }
        
    }
};