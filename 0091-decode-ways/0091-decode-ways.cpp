class Solution {
public:
vector<int>dp;
int f(int idx,string&s){
    int n=s.size();
    if(idx>n)return 0;
    if(idx==s.size())return 1;
   
    if(s[idx]=='0')return 0;
     if(dp[idx]!=-1)return dp[idx];
    int ans=0;
    ans+=f(idx+1,s);
    if(idx<=(n-2)){     int num=(s[idx]-'0')*10+s[idx+1]-'0';
    if(num<=26)ans+=f(idx+2,s);
    }
    return dp[idx]=ans;
}
    int numDecodings(string s) {
        int n=s.size();
        dp.clear();
        dp.resize(n+1,-1);
        return f(0,s);
    }
};