class Solution {
public:
int dp[101][101];
bool f(int i,int j,string& s1,string& s2,string &s3){
     int p=s1.size(),q=s2.size(),r=p+q;
     if(i==p){
        while(j<q and i+j<r){
            if(s2[j]!=s3[i+j])return false;
            j++;
        }
        return true;
     }
      if(j==q){
        while(i<p and i+j<r){
            if(s1[i]!=s3[i+j])return false;
            i++;
           
        }
        return true;
     }
     if(dp[i][j]!=-1)return dp[i][j];
      bool ans=false;
    if(s1[i]==s3[i+j]){
        ans=ans||f(i+1,j,s1,s2,s3);
    }
    if(s2[j]==s3[i+j]){
        ans=ans||f(i,j+1,s1,s2,s3);
    }
    return dp[i][j]=ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        if((int)s3.size()!=(int)s1.size()+(int)s2.size())return false;
        memset(dp,-1,sizeof(dp));
        return f(0,0,s1,s2,s3);
    }
};