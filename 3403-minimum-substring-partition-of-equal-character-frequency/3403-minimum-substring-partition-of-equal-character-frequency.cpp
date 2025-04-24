class Solution {
public:
int dp[1002];
bool check(vector<int>&freq){
    int k=freq.size();
    int desire=0;
    for(int i=0;i<26;i++){
        if(freq[i]!=0 and desire==0){
            desire=freq[i];
        }
        else if(freq[i]!=0 and desire!=freq[i])
        return false;
         
    }
    return true;
}
int f(int i,string &s){
  
    int n=s.size();
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
vector<int>freq(26,0);
int ans=1e7;
for(int j=i;j<n;j++){
    
  freq[s[j]-'a']++;
  if((check(freq))){
    ans=min(ans,1+f(j+1,s));
  }
}
return dp[i]=ans;
}
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        
       memset(dp,-1,sizeof(dp));
        return f(0,s);
    }
};