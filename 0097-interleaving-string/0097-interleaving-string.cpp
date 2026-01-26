class Solution {
public:
int dp[101][101][201];
bool f(int i,int j,int k,string& s1,string& s2,string &s3){
     int p=s1.size(),q=s2.size(),r=s3.size();
     if(i==p){
        while(j<q and k<r){
            if(s2[j]!=s3[k])return false;
            j++;
            k++;
        }
        return true;
     }
      if(j==q){
        while(i<p and k<r){
            if(s1[i]!=s3[k])return false;
            i++;
            k++;
        }
        return true;
     }
     if(dp[i][j][k]!=-1)return dp[i][j][k];
      bool ans=false;
    if(s1[i]==s3[k]){
        ans=ans||f(i+1,j,k+1,s1,s2,s3);
    }
    if(s2[j]==s3[k]){
        ans=ans||f(i,j+1,k+1,s1,s2,s3);
    }
    return dp[i][j][k]=ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        if((int)s3.size()!=(int)s1.size()+(int)s2.size())return false;
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,s1,s2,s3);
    }
};