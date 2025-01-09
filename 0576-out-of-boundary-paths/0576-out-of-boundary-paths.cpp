class Solution {
public:
int dp[51][52][52];
int mod=1e9+7;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
 int f(int sr,int sc,int m,int n,int mmv){
    //  cout<<sr<<" "<<sc<<" "<<m<<" "<<n<<" "<<mmv<<" "<<endl;
    //  if(mmv==0||mmv<0)return 0;
    if((sr>m||sr<0||sc>n||sc<0) ){
       return 1;
    }
    if(mmv<0 ||mmv==0)return 0;
    // if(mmv==0||mmv<0)return 0;
    // cout<<sr<<" "<<sc<<" "<<m<<" "<<n<<" "<<mmv<<" "<<endl;
    if(dp[sr][sc][mmv]!=-1)return dp[sr][sc][mmv];
    int countways=0;
    for(int k=0;k<4;k++){
        if(mmv>=1){ 
            int newmv=mmv-1;    
               countways=((countways)%mod+(f(sr+dir[k][0],sc+dir[k][1],m,n,newmv))%mod)%mod;
        }
    }
    return dp[sr][sc][mmv]=countways;

 }
    int findPaths(int m, int n, int mmv, int sr, int sc) {
        m--;
        n--;
        memset(dp,-1,sizeof(dp));
        return f(sr,sc,m,n,mmv);
    }
};