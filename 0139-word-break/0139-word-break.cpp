class Solution {
public:
unordered_set<string>st;
vector<int>dp;
bool f(int idx,string &s){
   int n=s.size();
   if(idx==n)return true;
   if(dp[idx]!=-1)return dp[idx];
   
    for(int j=idx;j<n;j++){
        string t=s.substr(idx,j-idx+1);
        if(st.find(t)!=st.end() and f(j+1,s)){
            dp[idx]=1;
            return true;
        }
        else{
          continue;
        }   
    }    
        dp[idx]=0;
        return false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
          for(auto it:wordDict)
          st.insert(it);

          
        dp.clear();
        dp.resize(n+1,-1);
        return f(0,s);
    }
};