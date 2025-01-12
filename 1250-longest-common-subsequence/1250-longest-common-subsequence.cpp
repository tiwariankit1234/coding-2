//https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
int dp[1005][1005];

 int f(string& s1,string& s2,int i,int j){ //f(s1,s2,i,j) calculates the longest common subsequence
    if(i>=s1.size())return 0;
    if(j>=s2.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])
    return dp[i][j]=1+f(s1,s2,i+1,j+1);
    else
    {
        return dp[i][j]=max(f(s1,s2,i,j+1),f(s1,s2,i+1,j));
    }
    return 1;
 }
    int longestCommonSubsequence(string s1, string s2) {
    
     memset(dp,-1,sizeof dp);
     return f(s1,s2,0,0);
     int ans=0;
      for(int i=s1.size()-1;i>=0;i--){
        for(int j=s2.size();j>=0;j--){
            if(s1[i]==s2[j])
            dp[i][j]=1+dp[i+1][j+1];
            else
            dp[i][j]=max(dp[i][j+1],dp[i+1][j]);

        }
      }
    
    
        return dp[0][0];
    }
};

//
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length(), n = text2.length();
//         int dp[m][n];

//         dp[0][0] = text1[0]==text2[0] ? 1 : 0 ;


//         for(int i=1;i<m;i++){
//             dp[i][0] = (text1[i]==text2[0] && dp[i-1][0]!=1) ? 1 + dp[i-1][0] : dp[i-1][0] ;
//         }

//         for(int i=1;i<n;i++){
//             dp[0][i] = (text1[0]==text2[i]&&  dp[0][i-1] !=1) ? 1 + dp[0][i-1] : dp[0][i-1] ;
//         }

//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[i][j] = text1[i]==text2[j] ? 1 + dp[i-1][j-1] : max (dp[i-1][j],dp[i][j-1]) ;
//             }
//         }

//         return dp[m-1][n-1];
//     }
// };