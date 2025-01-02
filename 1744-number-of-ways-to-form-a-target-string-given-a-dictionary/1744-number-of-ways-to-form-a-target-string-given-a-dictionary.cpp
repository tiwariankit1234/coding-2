#define ll long long
class Solution {
public:

ll dp[1003][1003];
ll f(int i,int j,vector<vector<int>>&charfrequency,string& t){
  if(j==t.size() and i==(charfrequency.size())){
    return 1;
  }
  if(j==t.size())return 1;
  if(i==charfrequency.size())return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    ll countways=0;
   ll index=t[j]-'a';
     int take=(charfrequency[i][index]*f(i+1,j+1,charfrequency,t))% 1000000007;
     //not take
     int nottake=f(i+1,j,charfrequency,t);
     countways=take+nottake;
     return dp[i][j]=countways% 1000000007;
}
    int numWays(vector<string>& words, string t) {
        int n=words.size();
        int k=words[0].size();
        vector<vector<int>>charfrequency(k,vector<int>(26,0));
        
       for(auto it:words){
        int l=it.size();
        for(int j=0;j<l;j++){
            charfrequency[j][it[j]-'a']++;
        }
       }
        memset(dp,-1,sizeof(dp));
        return f(0,0,charfrequency,t);
       

    }
};