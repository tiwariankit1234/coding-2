class Solution {
public:
bool ispal[2002][2002];
int dp[2002];
int solve(int idx,string &s){
    int n=s.size();
    if(idx==n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int ans=INT_MAX;
    for(int j=idx;j<n;j++){
        if(ispal[idx][j]){
            if(j==n-1){
                ans=0;
            }
            else{
                ans=min(ans,1+solve(j+1,s));
            }
        }
    }
    return dp[idx]=ans;
}
    int minCut(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        memset(ispal,false,sizeof(ispal));
        for(int len=1;len<=n;len++){
            for(int i=0;(i+len-1)<n;i++){
                int j=i+len-1;
                if(s[i]==s[j] and (len<=2 || ispal[i+1][j-1])){
                    ispal[i][j]=true;
                }
            }
        }
        return solve(0,s);
    }
};